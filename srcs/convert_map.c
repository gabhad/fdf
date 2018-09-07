/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:25:27 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/07 15:25:29 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_lines(t_prog *prog)
{
	int		i;
	t_line	*temp;

	i = 1;
	temp = prog->first_line;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void		convert_map(t_prog *prog)
{
	char	**map;

	prog->grid->width = count_lines(prog);
	map = (char**)malloc(sizeof(char*) * lines + 1)
}
