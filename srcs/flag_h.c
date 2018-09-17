/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_h.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:22:36 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/14 15:22:46 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	flag_h(t_prog *prog)
{
	ft_printf("fdf allows you to draw a 3D representation of a map using ");
	ft_printf("wireframes (fils de fer).\nFor the best use of the program, ");
	ft_printf("your map should be rectangle or square and, if specified,\n");
	ft_printf("the size of the window should be coherent with the size of ");
	ft_printf("the map.\nMore details concerning the use of the function ");
	ft_printf("on its usage (./fdf).\n");
	ft_printf("%C", 0xA9);
	ft_printf("GH 2018\n");
	clear_struct(prog);
	exit(0);
}
