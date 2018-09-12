/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:11:06 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/07 08:11:42 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rectangle_map(t_prog *prog)
{
	ft_printf("Please enter a valid rectangle or square map.\n");
	clear_struct(prog);
	exit(0);
}

void	malloc_error(t_prog *prog)
{
	ft_printf("Memory allocation error.\n");
	clear_struct(prog);
	exit(0);
}

void	no_map(t_prog *prog)
{
	ft_printf("Please input a valid file.\n");
	clear_struct(prog);
	exit(0);
}

void	multi_maps(t_prog *prog)
{
	ft_printf("Please input one file only.\n");
	clear_struct(prog);
	exit(0);
}

void	error(t_prog *prog)
{
	clear_struct(prog);
	write(1, "Error.\n", 7);
	exit(0);
}
