/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 00:42:10 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/08 00:49:44 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str)
{
	int end_ctr;
	int beg_ctr;

	end_ctr = ft_strlen(str);
	beg_ctr = 0;
	end_ctr--;
	while (beg_ctr < end_ctr)
	{
		ft_swap((void *)str + beg_ctr, (void *)str + end_ctr, sizeof(char));
		beg_ctr++;
		end_ctr--;
	}
	return (str);
}
