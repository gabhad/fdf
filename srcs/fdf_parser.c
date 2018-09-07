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

void	flag_parser(int argc, char **argv, t_prog *prog)
{
	int			i;

	i = 1;
	while (argv[i])
	{
		while (argv[i] && argv[i][0] != '-')
			i++;
		if (argv[i][0] == '-' && argv[i][1] == 's')
			flag_s(prog, argv, i);

	}
}

void	fdf_parser(int argc, char **argv)
{
	t_prog		*prog;

	prog = NULL;
	prog = init_prog(prog);
	if (argc > 2)
		flag_parser(argc, argv, prog);
	read_map(argc_argv);
}
