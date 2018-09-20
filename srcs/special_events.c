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
	if (keycode == 53)
		quit_program(prog);
	return (1);
	if (keycode > 122 && keycode < 127)
	{
		mlx_destroy_image(prog->init, prog->img);
		if (keycode == 123)
			prog->a = prog->a - 15;
		else if (keycode == 124)
			prog->a = prog->a + 15;
		else if (keycode == 125)
			prog->b = prog->b + 15;
		else if (keycode == 126)
			prog->b = prog->b - 15;
		draw_img(prog, prog->a, prog->b);
	}
}

void		special_events(t_prog *prog)
{
	mlx_hook(prog->window, 2, 0, *(key_press), (t_prog*)prog);
	//mlx_hook(prog->window, 17, 0, (void*)(quit_program), (t_prog*)prog);
}
