/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_next_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:57:57 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/20 13:58:06 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_next_pixel(t_prog *p, int i, int j)
{
	int	pix;
	int el;

	el = p->number_map[i][j] * 1.2;

	pix = p->start + (i - j + el) * p->y_step + (i + j) * p->x_step;
	p->array[pix] = 0x00FFFFFF;
//	join_pixels(p, i, j);
}
