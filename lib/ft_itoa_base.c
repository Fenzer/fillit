/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:57:33 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/24 11:49:29 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int n, int base)
{
	char	char_base[17];
	int		i;
	char	c;

	c = '0';
	i = 0;
	if (base < 2 || base > 16)
		return (NULL);
	while (i < base)
	{
		char_base[i++] = c++;
		if (c == '9' + 1)
			c = 'A';
	}
	char_base[i] = 0;
	return (ft_itoa_cbase(n, char_base));
}
