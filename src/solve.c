/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:45:24 by fepinson          #+#    #+#             */
/*   Updated: 2019/10/02 23:08:04 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		place_tetri(t_tetri *tetri, t_map *map, int mode)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (mode)
			map->mp[tetri->coord[i].y + tetri->pt.y]
				[tetri->coord[i].x + tetri->pt.x] = tetri->order;
		else
			map->mp[tetri->coord[i].y + tetri->pt.y]
				[tetri->coord[i].x + tetri->pt.x] = '.';
		++i;
	}
}

/*int		get_next_pos(t_tetri *tetri, t_map *map)*/
/*{*/
	/*int	y;*/
	/*int	x;*/

	/*y = 0;*/
	/*while (y < map->sz - tetri->mx.y + 1)*/
	/*{*/
		/*x = 0;*/
		/*while (x < map->sz - tetri->mx.x + 1)*/
		/*{*/
			/*if (map->mp[y][x] == '.')*/
			/*{*/
				/*set_point(&tetri->pt, x, y);*/
				/*if (check_fit(tetri, map))*/
					/*return (1);*/
			/*}*/
			/*++x;*/
		/*}*/
		/*++y;*/
	/*}*/
	/*set_point(&tetri->pt, 0, 0);*/
	/*return (0);*/
/*}*/

int		solve_map(t_tetri *tetri, int i, t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->sz - tetri->mx.y + 1)
	{
		x = -1;
		while (++x < map->sz - tetri->mx.x + 1)
		{
			if (map->mp[y][x] == '.' && check_fit(tetri, map, x, y))
			{
				place_tetri(tetri, map, 1);
				if (!i)
					return (1);
				else if (solve_map(tetri + 1, i - 1, map))
					return (1);
				else
					place_tetri(tetri, map, 0);
			}
		}
	}
	return (0);
}

int		check_fit(t_tetri *tetri, t_map *map, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < tetri->mx.y && y + i < map->sz)
	{
		j = -1;
		while (++j < tetri->mx.x && y + j < map->sz)
			if (tetri->tetri[i][j] == '#' && map->mp[y + i][x + j] != '.')
				return (0);
	}
	set_point(&tetri->pt, x, y);
	return (1);
}

t_map	*init_map(int sz)
{
	t_map	*map;
	int		i;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->sz = sz;
	if (!(map->mp = (char **)ft_memalloc(sizeof(char *) * (sz + 1))))
		return (NULL);
	i = 0;
	while (i < sz)
	{
		if (!(map->mp[i] = (char *)ft_memalloc(sizeof(char *) * (sz + 1))))
			return (NULL);
		else
			ft_memset((void *)map->mp[i++], '.', sz);
	}
	return (map);
}
