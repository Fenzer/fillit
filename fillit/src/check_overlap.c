/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overlap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:40:40 by liferrer          #+#    #+#             */
/*   Updated: 2019/02/04 17:39:15 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_overlap(t_tetri *forme1, t_tetri *forme2)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((*forme1)[i].coord[i][0] == (*forme2)[i].coord[i][0]
				&& (*forme1)[i].coord[i][1] == (*forme2)[i].coord[i][1])
			return (0);
		else
			i++;
	}
	return (1);
}
