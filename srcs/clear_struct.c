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

void	clear_struct(t_prog *prog)
{
	free(prog->grid);
	free(prog->prog);
	free(prog->init);
	free(prog->window);
	free(prog->img);
}
