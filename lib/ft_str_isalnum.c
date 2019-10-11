/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isalnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <pinsonfen@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:15:22 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/08 01:09:14 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isalnum(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		if (!ft_isalnum(str[i++]))
			return (0);
	return (1);
}
