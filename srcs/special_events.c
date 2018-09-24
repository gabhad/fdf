/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:42:51 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/17 14:43:02 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_press(int keycode, t_prog *prog)
{
	if (keycode == ESC)
		quit_program(prog);
	return (1);
	if (keycode > 122 && keycode < 127)
	{
		mlx_destroy_image(prog->init, prog->img);
		if (keycode == LEFT)
			prog->a = prog->a - 50;
		else if (keycode == RIGHT)
			prog->a = prog->a + 50;
		else if (keycode == DOWN)
			prog->b = prog->b + 50;
		else if (keycode == UP)
			prog->b = prog->b - 50;
		draw_img(prog, prog->a, prog->b);
	}
}

void		special_events(t_prog *prog)
{
	mlx_hook(prog->window, 2, 0, *(key_press), (t_prog*)prog);
	mlx_hook(prog->window, 17, 0, (void*)(quit_program), (t_prog*)prog);
}
