/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:19:19 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/24 18:19:26 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void y_big(t_prog *p, int x1, int y1, int coord)
{
	int	x2;
	int	y2;
	int y;
	int	fault;

	y = y1;
	x2 = coord % p->win_w;
	y2 = (coord - x2) / p->win_w;
	fault = abs(y2 - y1) / 2;
	while (x1 != x2)
	{
		fault = fault - (x2 - x1);
		if (fault > 0)
		{
			if (y > y2)
				put_pixel(p, x1, y1--, WHITE);
			else
				put_pixel(p, x1, y1++, WHITE);
		}
		else
		{
			if (y > y2)
				put_pixel(p, x1++, y1--, WHITE);
			else
				put_pixel(p, x1++, y1++, WHITE);
			fault = fault + abs(y2 - y1);
		}
	}
}

static void	x_big(t_prog *p, int x1, int y1, int coord)
{
	int	x2;
	int	y2;
	int	fault;
	int	y;

	y = y1;
	x2 = coord % p->win_w;
	y2 = (coord - x2) / p->win_w;
	fault = (x2 - x1) / 2;
	while (x1 != x2)
	{
		fault = fault - abs(y2 - y1);
		if (fault > 0)
			put_pixel(p, x1++, y1, WHITE);
		else
		{
			if (y > y2)
				put_pixel(p, x1++, y1--, WHITE);
			else
				put_pixel(p, x1++, y1++, WHITE);
			fault = fault + x2 - x1;
		}
	}
}

void		bresenham(t_prog *p, int x1, int y1, int coord)
{
	int	x2;
	int	y2;

	x2 = coord % p->win_w;
	y2 = (coord - x2) / p->win_w;
	if (x2 - x1 < abs(y2 - y1))
		y_big(p, x1, y1, coord);
	else
		x_big(p, x1, y1, coord);
}
