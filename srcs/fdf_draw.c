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

void		fdf_draw(t_prog *prog)
{
	init_draw(prog);
	init_img(prog);
	special_events(prog);
	mlx_loop(prog->init);
}
