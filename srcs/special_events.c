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

static void	refresh(t_prog *prog)
{
	prog->a = 50;
	prog->b = 50;
	prog->x_step = 0;
	prog->y_step = 0;
}

static void	test_zoom(int keycode, t_prog *prog)
{
	if (keycode == ZOOM_IN)
	{
		prog->x_step++;
		prog->y_step++;
	}
	else if (keycode == ZOOM_OUT && prog->x_step > 2 && prog->y_step > 2)
	{
		prog->x_step--;
		prog->y_step--;
	}
}

static int	key_press(int keycode, t_prog *prog)
{
	if (keycode == ESC)
		quit_program(prog);
	if ((keycode > 122 && keycode < 127)
		|| keycode == ZOOM_IN || keycode == ZOOM_OUT || keycode == REF)
	{
		mlx_destroy_image(prog->init, prog->img);
		if (keycode == LEFT)
			prog->a = prog->a - 10;
		else if (keycode == RIGHT)
			prog->a = prog->a + 10;
		else if (keycode == DOWN)
			prog->b = prog->b + 10;
		else if (keycode == UP)
			prog->b = prog->b - 10;
		else if (keycode == REF)
			refresh(prog);
		else
			test_zoom(keycode, prog);
		fdf_draw(prog);
	}
	return (1);
}

void		special_events(t_prog *prog)
{
	mlx_hook(prog->window, 2, 0, *(key_press), (t_prog*)prog);
	mlx_hook(prog->window, 17, 0, (void*)(quit_program), (t_prog*)prog);
}
