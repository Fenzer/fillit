/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <pinsonfen@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 10:09:24 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/04 16:17:01 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if ((s = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
	{
		while (str && str[i])
		{
			s[i] = str[i];
			++i;
		}
		s[i] = 0;
	}
	return (s);
}
