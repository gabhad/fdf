/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:04:58 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/07 14:05:10 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map(t_prog *prog)
{
	char	*line;

	line = NULL;
	if (get_next_line(prog->fd, &line) < 1)
		no_map(prog);
	prog->map = ft_strjoinfree(prog->map, line);
	prog->map = ft_strjoinfree(prog->map, ft_strdup("\n"));
	while (get_next_line(prog->fd, &line))
	{
		prog->map = ft_strjoinfree(prog->map, line);
		prog->map = ft_strjoinfree(prog->map, ft_strdup("\n"));
	}
	convert_map(prog);
}
