/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:04:39 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/17 16:04:46 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	quit_program(t_prog *prog)
{
	mlx_destroy_image(prog->init, prog->img);
	mlx_clear_window(prog->init, prog->window);
	mlx_destroy_window(prog->init, prog->window);
	exit(0);
}
