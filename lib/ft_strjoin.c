/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:16:55 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/04 17:37:49 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s;
	char		*rt;

	rt = NULL;
	if (s1 && s2)
	{
		if ((s = (char *)malloc(sizeof(char)
						* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		{
			rt = s;
			while (s1 && *s1)
				*s++ = *s1++;
			while (s2 && *s2)
				*s++ = *s2++;
			*s = 0;
		}
	}
	return (rt);
}
