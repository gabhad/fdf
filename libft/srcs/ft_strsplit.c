/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:14:25 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/20 16:04:34 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word(char const *s, char delim)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == delim && s[i])
			i++;
		if (s[i] != delim && s[i])
			word++;
		while (s[i] != delim && s[i])
			i++;
	}
	return (word);
}

static int		ft_lettercount(char const *s, char delim)
{
	int i;
	int letter;

	i = 0;
	letter = 0;
	while (s[i] && s[i] != delim)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	**tab;

	i = 0;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char*) * (word(s, c) + 1))))
		return (NULL);
	while (s[i] && j < word(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		count = ft_lettercount(&s[i], c);
		if (!(tab[j] = (char *)malloc(sizeof(char) * (count + 1))))
			return (NULL);
		while (s[i] && s[i] != c && (k < count))
			tab[j][k++] = s[i++];
		tab[j][k] = 0;
		j++;
	}
	tab[j] = 0;
	return (tab);
}
