/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_next_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:57:57 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/20 13:58:06 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_prog *prog, int x, int y, int color)
{
	int	pix;

	pix = y * prog->win_w + x;
	prog->array[pix] = color;
}

static void	draw_line(t_prog *p, int i, int j, int coord)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x2 = coord % p->win_w;
	y2 = (coord - x2) / p->win_w;
	x1 = (i + j) * p->x_step + p->a;
	y1 = p->win_h / 2 + (j - i + p->number_map[i][j] * 1.3) * p->y_step;
	if ((x2 - x1) == (y2 - y1))
		while (x1 != x2)
			put_pixel(p, ++x1, ++y1, WHITE);
	else if ((x2 - x1) == (y1 - y2))
		while (x1 != x2)
			put_pixel(p, ++x1, --y1, WHITE);
	else
		bresenham(p, x1, y1, coord);
}

void		place_next_pixel(t_prog *p, int i, int j)
{
	int	x;
	int y;
	int	el;

	el = p->number_map[i][j] * 1.3;
	x = (i + j) * p->x_step + p->a;
	y = p->win_h / 2 + (j - i + el) * p->y_step;
	put_pixel(p, x, y, WHITE);
	if (i > 0)
		draw_line(p, i - 1, j, y * p->win_w + x);
	if (j > 0)
		draw_line(p, i, j - 1, y * p->win_w + x);
}
