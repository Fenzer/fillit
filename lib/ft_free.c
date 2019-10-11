/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_msg_ret.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:59:16 by fepinson          #+#    #+#             */
/*   Updated: 2019/10/08 11:44:17 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free(void *p, char *s, int i, void (*ft_free) (void *))
{
	if (s)
		ft_putendl(s);
	if (p)
	{
		if (!ft_free)
			free(p);
		else
			ft_free(p);
	}
	return (i);
}
