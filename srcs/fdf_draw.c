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

static void	init_img(t_prog *prog)
{
	int		*array;
	void	*img;

	img = mlx_new_image(prog->init, prog->win_w, prog->win_h);
	prog->img = img;
	array = (int*)mlx_get_data_addr(img, &prog->bpp, &prog->s_l, &prog->endian);
	prog->array = array;
}

static void	init_draw(t_prog *prog)
{
	void	*init;
	void	*window;

	init = mlx_init();
	window = mlx_new_window(init, prog->win_w, prog->win_h, prog->title);
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
	if ((x < 5 || y < 4) && prog->flag_s)
		size_error(prog, 4 * z + 100);
	if (x < 4 && !prog->flag_s)
		prog->win_w = 4 * z + 100;
	if (y < 4 && !prog->flag_s)
		prog->win_h = 4 * z + 100;
}

void		draw_img(t_prog *prog, int a, int b)
{
	int		start;
	int		i;
	int		j;

	start = (prog->grid->width * prog->x_step + b) * prog->win_w + a;
	prog->start = start;
	i = 0;
	j = 0;
	while (i < prog->grid->height)
	{
		while (j < prog->grid->width)
		{
			place_next_pixel(prog, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void		fdf_draw(t_prog *p)
{
	int		*array;
	int		x_step;
	int		y_step;

	if (!p->x_step && !p->y_step)
	{
		x_step = (p->win_w - 100) / (p->grid->width + p->grid->height);
		y_step = (p->win_h - 100) / (p->grid->width + p->grid->height);
		p->x_step = x_step;
		p->y_step = y_step;
		resize_map(p);
		init_draw(p);
	}
	init_img(p);
	array = (int*)mlx_get_data_addr(p->img, &p->bpp, &p->s_l, &p->endian);
	p->array = array;
	draw_img(p, p->a, p->b);
	mlx_put_image_to_window(p->init, p->window, p->img, 0, 0);
	special_events(p);
	mlx_loop(p->init);
}
