/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <pinsonfen@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:59:10 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/04 17:39:54 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *string, const char *substring)
{
	const char *a;
	const char *b;

	b = substring;
	if (*b == 0)
		return ((char *)string);
	while (*string != 0)
	{
		if (*string == *b)
		{
			a = string;
			while (1)
			{
				if (*b == 0)
					return ((char *)string);
				if (*a++ != *b++)
					break ;
			}
			b = substring;
		}
		string += 1;
	}
	return (NULL);
}
