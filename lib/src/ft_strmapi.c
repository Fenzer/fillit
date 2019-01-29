/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:16:55 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/04 18:42:41 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char		*r;
	int			i;

	i = -1;
	r = NULL;
	if (s && (r = (char *)
				malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		while (s[++i])
			r[i] = f((unsigned int)i, s[i]);
		r[i] = 0;
	}
	return (r);
}
