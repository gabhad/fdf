/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:53:58 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/05 09:54:00 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	flag_parser(char **argv, int i, t_prog *prog)
{
	if (argv[i][0] != '-')
	{
		clear_struct(prog);
		usage();
	}
	else if (argv[i][1] == 's')
		flag_s(prog, argv, i);
	else
	{
		clear_struct(prog);
		usage();
	}
}

void		fdf_parser(int argc, char **argv)
{
	t_prog		*prog;
	int			i;
	int			fd;

	prog = NULL;
	prog = init_prog(prog);
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd > -1 && prog->fd < 1)
			prog->fd = fd;
		else if (fd > 0 && prog->fd > 0)
			multi_maps(prog);
		else
		{
			flag_parser(argv, i, prog);
			i++;
		}
		i++;
	}
	if (prog->fd < 1)
		no_map(prog);
	read_map(prog);
	close(prog->fd);
}
