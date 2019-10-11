/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <pinsonfen@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:25:31 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/09 17:09:36 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isalpha(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		if (!ft_isalpha(str[i++]))
			return (0);
	return (1);
}
