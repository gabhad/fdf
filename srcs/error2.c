/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:05:42 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/11 11:05:51 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	invalid_map(t_prog *prog)
{
	ft_printf("Please enter only valid chars - Numbers 0-9, +/-, spaces ");
	ft_printf("and line return.\nNo letters, tabulations or special chars\n");
	clear_struct(prog);
	exit(0);
}

void	error_title(t_prog *prog)
{
	ft_printf("Please enter a valid title - Less than 15 chars, only");
	ft_printf(" printable chars\n");
	clear_struct(prog);
	exit(0);
}

void	size_error(t_prog *prog, int i)
{
	ft_printf("For comfort reasons, please enter a valid window size (Min ");
	ft_printf("%dx%d).\n", i, i);
	clear_struct(prog);
	exit(0);
}

void	map_too_big(t_prog *prog)
{
	ft_printf("The map you entered is too big (max 200x200)\n");
	clear_struct(prog);
	exit(0);
}

void	map_too_small(t_prog *prog)
{
	ft_printf("The map you entered is too small (min 2x2\n");
	clear_struct(prog);
	exit(0);
}
