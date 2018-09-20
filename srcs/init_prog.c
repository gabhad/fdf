/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:26:55 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/07 08:27:08 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_grid	*init_grid(t_prog *prog)
{
	t_grid	*grid;

	if (!(grid = (t_grid*)malloc(sizeof(t_grid))))
		error(prog);
	grid->width = -1;
	grid->height = -1;
	return (grid);
}

t_prog			*init_prog(t_prog *prog)
{
	if (!(prog = (t_prog*)malloc(sizeof(t_prog))))
		error(prog);
	prog->grid = init_grid(prog);
	prog->title = ft_strdup("fdf");
	prog->win_w = 800;
	prog->win_h = 800;
	prog->fd = -1;
	prog->color = 0x00FFFFFF;
	prog->map = NULL;
	prog->number_map = NULL;
	prog->init = NULL;
	prog->window = NULL;
	prog->img = NULL;
	prog->array = NULL;
	prog->flag_s = 0;
	prog->a = 0;
	prog->b = 0;
	return (prog);
}
