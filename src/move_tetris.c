/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:25:37 by liferrer          #+#    #+#             */
/*   Updated: 2019/04/24 03:02:21 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*void	move_tetris(int y, int x, t_tetri *tetris)*/
/*{*/
	/*int	i;*/

	/*i = 0;*/
	/*while (i < 4)*/
	/*{*/
		/*tetris->coord[i][0] += y;*/
		/*tetris->coord[i][1] += x;*/
		/*i++;*/
	/*}*/
/*}*/

int		check_fit(t_tetri *tetri, t_map *map)
{
	int	j;
	int sz;

	j = -1;
	sz = map->sz - 1;
	while (++j < 4)
		if (tetri->coord[j].x + tetri->pt.x > sz
			|| tetri->coord[j].y + tetri->pt.y > sz)
			return (0);
	return (1);
}

/*int		get_max(t_tetri *tetri, int i, int xy)*/
/*{*/
	/*int max;*/
	/*int j;*/

	/*max = 0;*/
	/*while (i >= 0)*/
	/*{*/
		/*j = -1;*/
		/*while (++j < 4)*/
			/*if (tetri->coord[j][xy] > max)*/
				/*max = tetri->coord[j][xy];*/
		/*i--;*/
	/*}*/
	/*return (max);*/
/*}*/

/*int		check_overlap(t_tetri *tetri1, t_tetri *tetri2)*/
/*{*/
	/*int j;*/
	/*int p1[2];*/
	/*int p2[2];*/

	/*p1[0] = tetri1->pos[0];*/
	/*p1[1] = tetri1->pos[1];*/
	/*p2[0] = tetri2->pos[0];*/
	/*p2[1] = tetri2->pos[1];*/
	/*j = -1;*/
	/*while (++j < 4)*/
		/*if (tetri1->coord[j][0] + p1[0] == tetri2->coord[j][0] + p2[0]*/
				/*&& tetri1->coord[j][1] + p1[1] == tetri2->coord[j][1] + p2[1])*/
			/*return (1);*/
	/*return (0);*/
/*}*/

/*int		find_overlap(t_tetri *tetri, int i)*/
/*{*/
	/*int	j;*/

	/*while (i >= 0)*/
	/*{*/
		/*j = i - 1;*/
		/*while (j >= 0)*/
			/*if (check_overlap(tetri + i, tetri + j--))*/
				/*return (i);*/
		/*--i;*/
	/*}*/
	/*return (0);*/
/*}*/
