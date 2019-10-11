/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:27:14 by fepinson          #+#    #+#             */
/*   Updated: 2018/12/11 22:05:34 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1p;
	const unsigned char *s2p;

	if (!n)
		return (0);
	s1p = (unsigned char *)s1;
	s2p = (unsigned char *)s2;
	while (n--)
		if (*s1p++ != *s2p++)
			return ((int)(*(--s1p) - *(--s2p)));
	return (0);
}
