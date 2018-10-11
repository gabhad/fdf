/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:08:47 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/07 09:08:57 by ghaddad          ###   ########.fr       */
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

void		clear_struct(t_prog *prog)
{
	if (prog->title)
		ft_strdel(&(prog->title));
	if (prog->init)
		free(prog->init);
	if (prog->window)
		free(prog->window);
	if (prog->img)
		free(prog->img);
	if (prog->map)
		ft_strdel(&(prog->map));
	if (prog->number_map)
		del_number(prog->number_map, prog->grid->height);
	if (prog->grid)
		free(prog->grid);
	if (prog->array)
		free(prog->array);
	if (prog->start)
		free(prog->start);
	free(prog);
}
