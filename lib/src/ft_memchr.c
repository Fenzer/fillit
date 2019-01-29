/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:56:07 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/04 16:06:17 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*str;
	size_t			i;

	uc = (unsigned char)c;
	str = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (str[i] == uc)
			return ((void *)s + i);
	return (NULL);
}
