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

static t_prog	init_grid(t_prog prog)
{
	t_grid	grid;

	if (!(grid = (t_grid)malloc(sizeof(t_grid))))
		error(prog);
	prog->grid = &grid;
	return (prog);
}

t_prog			init_prog(t_prog *prog)
{
	if (!(prog = (t_prog)malloc(sizeof(t_prog))))
		error(prog);
	prog->grid = init_grid(prog);
	prog->win_h = 600;
	prog->win_w = 800;
	return (prog);
}
