/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 00:47:30 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/08 19:39:11 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *p1, void *p2, size_t n)
{
	char buf[n];

	ft_memmove((void *)buf, p1, n);
	ft_memmove(p1, p2, n);
	ft_memmove(p2, (void *)buf, n);
}
