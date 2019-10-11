/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <pinsonfen@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:58:23 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/04 17:39:34 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *ret;

	ret = dst;
	while (n--)
	{
		if (*src)
			*dst++ = *src++;
		else
			*dst++ = 0;
	}
	return (ret);
}
