/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:55:23 by liferrer          #+#    #+#             */
/*   Updated: 2019/01/30 18:13:46 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	coord_tetris(char **str, t_tetri **tetris)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while ((*str)[i])
	{
		if ((*str)[x] == '#')
		{
			(*tetris)->coord[i][0] == y;
			(*tetris)->coord[i][1] == x;
			i++;
		}
		if ((*str)[x] == '\n')
		{
			y++;
			x = 0;
		}
		x++;
	}
}
