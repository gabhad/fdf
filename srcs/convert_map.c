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

static void	clean_table(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
}

static int	**generate_number(t_prog *prog, char ***tab)
{
	int		**number_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(number_map = (int**)malloc(sizeof(int*) * prog->grid->height)))
		malloc_error(prog);
	while (i < prog->grid->height)
	{
		if (!(number_map[i] = (int*)malloc(sizeof(int) * prog->grid->width)))
			malloc_error(prog);
		while (j < prog->grid->width)
		{
			number_map[i][j] = ft_atoi(tab[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	return (number_map);
}

void		convert_map(t_prog *prog)
{
	char	**tab;
	char	***tab2;
	int		i;

	prog->grid->height = count_lines(prog);
	if (!invalid_chars(prog->map))
		invalid_map(prog);
	if (!count(prog))
		rectangle_map(prog);
	i = -1;
	tab = ft_strsplit(prog->map, '\n');
	if (!(tab2 = (char***)malloc(sizeof(char**) * (prog->grid->height + 1))))
		malloc_error(prog);
	while (++i < prog->grid->width)
		tab2[i] = ft_strsplit(tab[i], ' ');
	prog->number_map = generate_number(prog, tab2);
	clean_table(tab);
	i = 0;
	while (i < prog->grid->height)
		clean_table(tab2[i++]);
	free(tab2);
}
