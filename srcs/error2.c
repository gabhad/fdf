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
