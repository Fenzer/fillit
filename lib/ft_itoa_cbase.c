/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_cbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:05:44 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/25 14:09:38 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (1);
}

char		*ft_itoa_cbase(int n, char *base)
{
	char	*str;
	long	d;
	long	l;
	long	bl;

	d = (n < 0 ? -1 : 1);
	l = 1;
	bl = (long)ft_strlen(base);
	while (n / d >= bl && ++l)
		d *= bl;
	if (!check_base(base) || !(str = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	str[l] = 0;
	l = 0;
	if (n < 0)
		str[l++] = '-';
	while (d < 0 ? d <= -bl : d >= bl)
	{
		str[l++] = base[n / d];
		n %= d;
		d /= bl;
	}
	str[l] = base[n / d];
	return (str);
}
