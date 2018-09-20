/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 10:46:57 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/18 10:47:07 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_img(t_prog *prog, int a, int b)
{
	int	start;
	int	x_step;
	int	y_step;
	int	i;
	int j;

	start = 5 * prog->win_h + prog->win_h * prog->win_w / 2 + 5 + a + b;
	x_step = (prog->win_w - 20) / (prog->grid->width + prog->grid->height);
	y_step = (prog->win_h - 20) / (prog->grid->width + prog->grid->height);
	prog->start = start;
	prog->x_step = x_step;
	prog->y_step = y_step;
	i = 0;
	j = 0;
	while (i < prog->grid->width)
	{
		while (j < prog->grid->height)
		{
			place_next_pixel(prog, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
