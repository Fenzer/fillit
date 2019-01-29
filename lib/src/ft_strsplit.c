/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:16:55 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/08 20:06:53 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_ctr_len(char *str, char sep, int m)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] != sep && (!str[i + 1] || str[i + 1] == sep))
		{
			if (!m)
				++n;
			else
				return (++i);
		}
		++i;
	}
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		n;
	int		i;

	i = 0;
	n = word_ctr_len((char *)s, c, 0);
	if (!(tab = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	tab[n] = 0;
	while (n--)
	{
		while (*s && *s == c)
			s++;
		tab[i] = ft_strsub((const char *)s, 0, word_ctr_len((char *)s, c, 1));
		if (!tab[i])
			return (NULL);
		s = s + ft_strlen(tab[i]);
		i++;
	}
	return (tab);
}
