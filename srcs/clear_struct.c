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

void		clear_lines(t_prog *prog)
{
	t_line	*temp;
	t_line	*tempbis;

	temp = prog->first_line;
	tempbis = NULL;
	while (temp->next)
	{
		tempbis = temp->next;
		ft_strdel(&(temp->line));
		free(temp);
		temp = tempbis;
	}
	ft_strdel(&(temp->line));
	free(temp);
}

void		clear_table(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		ft_strdel(map[i++]);
	free(map);
}

void		clear_struct(t_prog *prog)
{
	free(prog->grid);
	free(prog->prog);
	free(prog->init);
	free(prog->window);
	free(prog->img);
	if (map)
		clear_table(map);
	if (prog->first_line)
		clear_lines(prog);
}
