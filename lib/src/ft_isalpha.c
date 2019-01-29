/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <pinsonfen@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:25:31 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/04 02:19:35 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isupper(int c)
{
	return (c <= 'Z' && c >= 'A');
}

static int		ft_islower(int c)
{
	return (c <= 'z' && c >= 'a');
}

int				ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
