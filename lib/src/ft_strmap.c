/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:16:55 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/04 16:14:15 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	char		*r;
	int			i;

	i = 0;
	r = NULL;
	if (s && f
			&& (r = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1))))
	{
		while (s[i])
		{
			r[i] = f(s[i]);
			++i;
		}
		r[i] = 0;
	}
	return (r);
}
