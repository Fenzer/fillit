/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:05:47 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/04 14:59:22 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int n;

	if (!*s2)
		return ((char *)s1);
	n = ft_strlen(s2);
	while (*s1 && len-- >= (size_t)n)
	{
		if (*s1 == *s2 && !ft_memcmp(s1, s2, (size_t)n))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
