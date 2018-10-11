/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 09:59:13 by ghaddad           #+#    #+#             */
/*   Updated: 2018/10/11 09:59:27 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < prog->grid->height)
	{
		while (j < prog->grid->width)
		{
			ft_printf("[%d]", prog->number_map[i][j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
}
