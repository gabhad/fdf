/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:51:17 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/14 15:51:25 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_img(t_prog *p)
{
	int		*array;
	void	*img;

	if (!(img = mlx_new_image(p->init, p->win_w, p->win_h)))
		malloc_error(p);
	p->img = img;
	if (!(array = (int*)mlx_get_data_addr(img, &p->bpp, &p->s_l, &p->endian)))
		malloc_error(p);
	p->array = array;
}

static void	init_draw(t_prog *prog)
{
	void	*init;
	void	*window;

	if (!(init = mlx_init()))
		malloc_error(prog);
	if (!(window = mlx_new_window(init, prog->win_w, prog->win_h, prog->title)))
		malloc_error(prog);
	prog->init = init;
	prog->window = window;
}

static void	resize_map(t_prog *prog)
{
	int		x;
	int		y;
	int		z;

	z = prog->grid->width + prog->grid->height;
	x = prog->win_w / z;
	y = prog->win_h / z;
	if ((x < 3 || y < 3) && prog->flag_s)
		size_error(prog, 3 * z + 50);
	if (x < 4 && !prog->flag_s)
		prog->win_w = 4 * z + 100;
	if (y < 4 && !prog->flag_s)
		prog->win_h = 4 * z + 100;
}

void		draw_img(t_prog *p, int a, int b)
{
	t_point	*start;
	int		i;
	int		j;

	if (!p->start || p->start->x != a
		|| p->start->y != p->grid->width * p->x_step + b)
	{
		if (!(start = (t_point*)malloc(sizeof(t_point))))
			malloc_error(p);
		start->x = a;
		start->y = p->grid->width * p->x_step + b;
		p->start = start;
	}
	i = 0;
	j = 0;
	while (i < p->grid->height)
	{
		while (j < p->grid->width)
		{
			place_next_pixel(p, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void		fdf_draw(t_prog *p)
{
	int		x_step;
	int		y_step;

	if (!p->x_step && !p->y_step)
	{
		resize_map(p);
		x_step = (p->win_w - 100) / (p->grid->width + p->grid->height);
		y_step = (p->win_h - 100) / (p->grid->width + p->grid->height);
		p->x_step = x_step;
		p->y_step = y_step;
		if (p->verbal)
			print_map(p);
		init_draw(p);
	}
	init_img(p);
	draw_img(p, p->a, p->b);
	mlx_put_image_to_window(p->init, p->window, p->img, 0, 0);
	special_events(p);
	mlx_loop(p->init);
}
