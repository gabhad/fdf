/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:04:39 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/17 16:04:46 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	del_number(int **tab, int n)
{
	int		i;

	i = 0;
	while (i < n)
		free(tab[i++]);
	free(tab);
}

static void	clean_structure(t_prog *prog)
{
	if (prog->title)
		ft_strdel(&(prog->title));
	if (prog->map)
		ft_strdel(&(prog->map));
	if (prog->number_map)
		del_number(prog->number_map, prog->grid->height);
	if (prog->grid)
		free(prog->grid);
	if (prog->start)
		free(prog->start);
	free(prog);
}

void		quit_program(t_prog *prog)
{
	mlx_destroy_image(prog->init, prog->img);
	mlx_clear_window(prog->init, prog->window);
	mlx_destroy_window(prog->init, prog->window);
	clean_structure(prog);
	exit(0);
}
