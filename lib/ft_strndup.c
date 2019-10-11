/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:14:51 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/08 20:55:22 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t n)
{
	int		i;
	char	*rt;

	i = 0;
	if (!(rt = (char *)ft_memalloc(sizeof(char *) * (n + 1))))
		return (NULL);
	while (str[i] && n--)
	{
		rt[i] = str[i];
		i++;
	}
	return (rt);
}
