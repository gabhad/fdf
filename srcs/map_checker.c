/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:06:52 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/11 11:07:03 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_bis(t_prog *prog, int i)
{
	int		j;

	j = 0;
	while (prog->map[i] != '\n')
	{
		while (prog->map[i] == ' ')
			i++;
		if (prog->map[i] != ' ' && prog->map[i] != '\n')
			j++;
		while (prog->map[i] != ' ' && prog->map[i] != '\n')
			i++;
	}
	prog->grid->width < 0 ? prog->grid->width = j : 0;
	if (j != prog->grid->width)
		return (0);
	return (i);
}

int			count(t_prog *prog)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < prog->grid->height)
	{
		if (!(i = count_bis(prog, i)))
			return (0);
		i++;
		j++;
	}
	return (1);
}

int			invalid_chars(char *map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if ((map[i] < '0' || map[i] > '9') && map[i] != ' ' && map[i] != '\n'
			&& map[i] != '+' && map[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int			count_lines(t_prog *prog)
{
	int		line;
	int		i;

	i = 0;
	line = 0;
	while (prog->map[i])
	{
		if (prog->map[i] == '\n')
			line++;
		i++;
	}
	if (prog->map[i - 1] != '\n')
		line++;
	return (line);
}
