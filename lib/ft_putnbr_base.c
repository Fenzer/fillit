/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <pinsonfen@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 19:02:53 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/08 19:33:13 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	n;

	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if ((base_len = ft_strlen(base)) < 2)
		return ;
	if (n > base_len)
	{
		ft_putnbr_base(n / base_len, base);
		ft_putchar(base[n % base_len]);
	}
	else
		ft_putchar(n + base[n]);
}
