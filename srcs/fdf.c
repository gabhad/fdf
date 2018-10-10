/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:41:12 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/05 09:41:16 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage(void)
{
	ft_printf("usage : ./fdf map.fdf [-t \"Title\"] [-s [WxH] ] -h for help\n");
	ft_printf("\tWhile using the program, zoom in/out using o/p\n");
	ft_printf("\tMove using arrow keys\n");
	ft_printf("\tIncrease/decrease altitude using +/-\n");
	ft_printf("\tClose the program using Esc.\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		usage();
	fdf_parser(argc, argv);
	return (0);
}
