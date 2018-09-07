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

static t_line	create_line(char *str);
{
	t_line	*line;

	if (!(line = (t_line*)malloc(sizeof(t_line))))
		malloc_error(prog);
	line->line = ft_strdup(*str);
	line->next = NULL;
	ft_strdel(str);
}

void	read_map(t_prog *prog)
{
	char	*line;

	if (get_next_line(prog->fd, &line) < 1)
		no_map(prog);
	create_line(line);
	while (get_next_line(prog->fd, &line))
		create_line(&line);
	convert_map(prog);
}