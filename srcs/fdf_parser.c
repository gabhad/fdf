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

static int	flag_parser(char **argv, int i, t_prog *prog)
{
	if (argv[i][0] != '-')
	{
		clear_struct(prog);
		usage();
	}
	else if (argv[i][1] == 's')
	{
		flag_s(prog, argv, i);
		return (1);
	}
	else if (argv[i][1] == 'h')
		flag_h(prog);
	else if (argv[i][1] == 't')
	{
		flag_t(prog, argv, i);
		return (1);
	}
	else if (argv[i][1] == 'v')
		prog->verbal = 1;
	else
	{
		clear_struct(prog);
		usage();
	}
	return (0);
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
		else if (flag_parser(argv, i, prog))
			i++;
		i++;
	}
	if (prog->fd < 1)
		no_map(prog);
	read_map(prog);
	close(prog->fd);
	fdf_draw(prog);
	clear_struct(prog);
}
