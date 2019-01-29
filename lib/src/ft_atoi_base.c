/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <pinsonfen@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 19:36:47 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/25 14:15:12 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *str, int base)
{
	char	char_base[17];
	int		i;
	char	c;

	c = '0';
	i = 0;
	if (base < 2 || base > 16)
		return (0);
	while (i < base)
	{
		char_base[i++] = c++;
		if (c == '9' + 1)
			c = 'A';
	}
	char_base[i] = 0;
	return (ft_atoi_cbase(str, char_base));
}
