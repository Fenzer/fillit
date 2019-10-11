/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strssplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 03:05:35 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/08 21:02:21 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_ctr_len(char *str, char *sep, int m)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (str && str[i])
	{
		if (!ft_strchr(sep, str[i])
				&& (!str[i + 1] || ft_strchr(sep, str[i + 1])))
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

char		**ft_strssplit(char const *s, char *sep)
{
	char	**tab;
	int		n;
	int		i;

	i = 0;
	n = word_ctr_len((char *)s, sep, 0);
	if (!(tab = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	tab[n] = 0;
	while (n--)
	{
		while (*s && ft_strchr(sep, *s))
			s++;
		tab[i] = ft_strsub((const char *)s, 0, word_ctr_len((char *)s, sep, 1));
		if (!tab[i])
			return (NULL);
		s = s + ft_strlen(tab[i]);
		i++;
	}
	return (tab);
}
