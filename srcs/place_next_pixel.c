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

	if (x < 0 || x > prog->win_w || y < 0 || y > prog->win_h)
		return ;
	pix = y * prog->win_w + x;
	//printf("x = %d - y %d\npix - %d\n", x, y, pix);
	prog->array[pix] = color;
}

static void	draw_line(t_prog *p, int i, int j, int coord)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	el;

	x2 = coord % p->win_w;
	y2 = coord / p->win_w;
	el = p->number_map[i][j];
	x1 = (i + j) * p->x_step + p->start % p->win_w;
	y1 = p->start / p->win_w + (i - j - STEP * el) * p->y_step;
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
	int el;

	el = p->number_map[i][j];
	x = (i + j) * p->x_step + p->start % p->win_w;
	y = p->start / p->win_w + (i - j - STEP * el) * p->y_step;
	//ft_printf("i = %d\nj = %d\n", i, j);
	//ft_printf("x = %d - y = %d\n", x, y);
	put_pixel(p, x, y, WHITE);
	if (i > 0)
		draw_line(p, i - 1, j, y * p->win_w + x);
	if (j > 0)
		draw_line(p, i, j - 1, y * p->win_w + x);
}
