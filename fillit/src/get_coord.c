/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:55:23 by liferrer          #+#    #+#             */
/*   Updated: 2019/01/31 16:39:57 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include <stdio.h>

void	get_new_coord(int min_y, int min_x, t_tetri **tetris)
{
	int i;

	i = 0;
	while (i < 4)
	{
		(*tetris)->coord[i][0] -= min_y;
		(*tetris)->coord[i][1] -= min_x;
		i++;
	}
}

void	coord_tetris(char **str, t_tetri **tetris)
{
	int i;
	int j;
	int	min_x;
	int min_y;

	i = 0;
	j = 0;
	min_x = 5;
	min_y = 5;
	while ((*str)[i])
	{
		if ((*str)[i] == '#')
		{
			(*tetris)->coord[j][0] = i / 5;
			(*tetris)->coord[j][1] = i < 5 ? i : i % 5;
			if ((*tetris)->coord[j][0] < min_y)
				min_y = (*tetris)->coord[j][0];
			if ((*tetris)->coord[j][1] < min_x)
				min_x = (*tetris)->coord[j][1];
			j++;
		}
		i++;
	}
	get_new_coord(min_y, min_x, tetris);
}

int	main(int ac, char **argv)
{
	char	*str;
	int 	i;
	t_tetri *tetris = malloc(sizeof(t_tetri));

	i = -1;
	str = ft_strdup(".##.\n..#.\n..#.\n....\n");
	coord_tetris(&str, &tetris);
	while (++i < 4)
		printf("y = %d ; x = %d\n", tetris->coord[i][0], tetris->coord[i][1]);
	return (0);
}
