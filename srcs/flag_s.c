/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:37:18 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/07 09:37:29 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	del_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
}

static void	invalid(void)
{
	ft_printf("Please enter valid dimensions (WxH - Min 300x300");
	ft_printf(" - Max 2560x1440)\n");
}

static char	**check_valid(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	if (!ft_strstr(str, "x"))
	{
		invalid();
		return (NULL);
	}
	tab = ft_strsplit(str, 'x');
	while (tab[i])
		i++;
	if (i > 2 || ft_atoi(tab[0]) < 300 || ft_atoi(tab[1]) < 300
				|| ft_atoi(tab[0]) > 2560 || ft_atoi(tab[1]) > 1440)
	{
		invalid();
		del_tab(tab);
		return (NULL);
	}
	return (tab);
}

void		flag_s(t_prog *prog, char **argv, int i)
{
	char	**tab;

	if (!argv[i + 1])
	{
		clear_struct(prog);
		usage();
	}
	if (!(tab = check_valid(argv[i + 1])))
	{
		clear_struct(prog);
		exit(0);
	}
	prog->win_w = ft_atoi(tab[0]);
	prog->win_h = ft_atoi(tab[1]);
	prog->flag_s = 1;
	del_tab(tab);
}
