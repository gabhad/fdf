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

static void	change_gradiant(t_prog *prog, int change)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < prog->grid->height)
	{
		while (j < prog->grid->width)
		{
			if (prog->number_map[i][j])
				prog->number_map[i][j] = prog->number_map[i][j] + change;
			j++;
		}
		j = 0;
		i++;
	}
}

static void	test_zoom(int keycode, t_prog *prog)
{
	if (keycode == ZOOM_IN)
	{
		prog->x_step++;
		prog->y_step++;
	}
	else if (keycode == ZOOM_OUT && prog->x_step > 3 && prog->y_step > 3)
	{
		prog->x_step--;
		prog->y_step--;
	}
	else if (keycode == PLUS)
		change_gradiant(prog, 1);
	else if (keycode == MINUS)
		change_gradiant(prog, -1);
}

static int	key_press(int keycode, t_prog *prog)
{
	if (keycode == ESC)
		quit_program(prog);
	if ((keycode > 122 && keycode < 127) || keycode == PLUS || keycode == MINUS
		|| keycode == ZOOM_IN || keycode == ZOOM_OUT)
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
