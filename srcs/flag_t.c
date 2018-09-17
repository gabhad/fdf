/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:08:04 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/14 16:08:14 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	flag_t(t_prog *prog, char **argv, int i)
{
	int	n;

	n = 0;
	if (!argv[i + 1])
	{
		clear_struct(prog);
		usage();
	}
	else
	{
		if (ft_strlen(argv[i + 1]) > 15)
			error_title(prog);
		while (argv[i + i][n])
			if (!isprint(argv[i + 1][n++]))
				error_title(prog);
		ft_strdel(&(prog->title));
		prog->title = ft_strdup(argv[i + 1]);
	}
}
