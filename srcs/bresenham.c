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

static void	y_big(t_prog *p, int x1, int y1)
{
	int y;
	int	fault;

	y = y1;
	fault = abs(p->point->y - y1) / 2;
	while (x1 != p->point->x)
	{
		fault = fault - (p->point->x - x1);
		if (fault > 0)
		{
			if (y > p->point->y)
				put_pixel(p, x1, y1--, WHITE);
			else
				put_pixel(p, x1, y1++, WHITE);
		}
		else
		{
			if (y > p->point->y)
				put_pixel(p, x1++, y1--, WHITE);
			else
				put_pixel(p, x1++, y1++, WHITE);
			fault = fault + abs(p->point->y - y1);
		}
	}
}

static void	x_big(t_prog *p, int x1, int y1)
{
	int	fault;
	int	y;

	y = y1;
	fault = (p->point->x - x1) / 2;
	while (x1 != p->point->x)
	{
		fault = fault - abs(p->point->y - y1);
		if (fault > 0)
			put_pixel(p, x1++, y1, WHITE);
		else
		{
			if (y > p->point->y)
				put_pixel(p, x1++, y1--, WHITE);
			else
				put_pixel(p, x1++, y1++, WHITE);
			fault = fault + p->point->x - x1;
		}
	}
}

void		bresenham(t_prog *p, int x1, int y1)
{
	if ((p->point->x - x1) < abs(p->point->y - y1))
		y_big(p, x1, y1);
	else
		x_big(p, x1, y1);
}
