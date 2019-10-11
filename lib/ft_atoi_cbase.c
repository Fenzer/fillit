/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_cbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:51:20 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/25 14:10:20 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_char_index(char c, char *str)
{
	int		i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

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

int			ft_atoi_cbase(const char *str, char *base)
{
	long	n;
	int		i;
	int		s;
	int		base_len;

	n = 0;
	i = 0;
	s = 1;
	if (!str || !base || (base_len = ft_strlen(base)) < 2 || !check_base(base))
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		s *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && find_char_index(str[i], base))
	{
		n *= base_len;
		n += find_char_index(str[i], base);
	}
	return (n < INT_MIN || n > INT_MAX ? 0 : n * s);
}
