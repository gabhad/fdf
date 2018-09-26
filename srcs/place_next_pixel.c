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

void		put_pixel(t_prog *prog, int x, int y, int color)
{
	int	pix;

	if (x < 1 || x > prog->win_w - 1 || y < 1 || y > prog->win_h - 1)
		return ;
	pix = y * prog->win_w + x;
	prog->array[pix] = color;
}

static void	draw_line(t_prog *p, int i, int j)
{
	int	x1;
	int	y1;
	int	el;

	el = p->number_map[i][j];
	x1 = (i + j) * p->x_step + p->start->x;
	y1 = p->start->y + (i - j - STEP * el) * p->y_step;
	if ((p->point->x - x1) == (p->point->y - y1))
		while (x1 != p->point->x)
			put_pixel(p, ++x1, ++y1, WHITE);
	else if ((p->point->x - x1) == (y1 - p->point->y))
		while (x1 != p->point->x)
			put_pixel(p, ++x1, --y1, WHITE);
	else
		bresenham(p, x1, y1);
}

void		place_next_pixel(t_prog *p, int i, int j)
{
	int		el;
	t_point *point;

	el = p->number_map[i][j];
	if (!(point = (t_point*)malloc(sizeof(t_point))))
		malloc_error(p);
	p->point = point;
	point->x = (i + j) * p->x_step + p->start->x;
	point->y = p->start->y + (i - j - STEP * el) * p->y_step;
	put_pixel(p, point->x, point->y, WHITE);
	if (i > 0)
		draw_line(p, i - 1, j);
	if (j > 0)
		draw_line(p, i, j - 1);
}
