/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:16:55 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/04 17:36:14 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		d;
	int		l;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	d = (n < 0 ? -1 : 1);
	l = (n < 0 ? 2 : 1);
	while (n / d > 9 && ++l)
		d *= 10;
	if (!(str = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	str[l] = 0;
	l = 0;
	if (n < 0)
		str[l++] = '-';
	while (d < 0 ? d < -9 : d > 9)
	{
		str[l++] = n / d + '0';
		n %= d;
		d /= 10;
	}
	str[l] = n / d + '0';
	return (str);
}
