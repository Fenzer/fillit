/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyncat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <pinsonfen@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:23:12 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/08 20:35:59 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dyncat(char *str1, char *str2, int n, int freemode)
{
	char	*final_str;
	int		i;
	int		j;

	if (!(final_str = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (str1 && str1[i] && i < n)
	{
		final_str[i] = str1[i];
		++i;
	}
	j = i;
	while (str2 && str2[j - i] && j < n)
	{
		final_str[j] = str2[j - i];
		++j;
	}
	final_str[n] = 0;
	if (freemode == 1)
		free(str1);
	else if (freemode == 2)
		free(str2);
	return (final_str);
}
