/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:45:24 by fepinson          #+#    #+#             */
/*   Updated: 2019/06/16 20:05:17 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_tetri(t_tetri *tetri, t_map *map, int mode)
{
	int i;

	i = -1;
	while (++i < 4)
		mode ? map->mp[tetri->coord[i].y + tetri->pt.y]
			[tetri->coord[i].x + tetri->pt.x] = tetri->order : '.';
}

int		get_next_pos(t_tetri *tetri, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->sz)
	{
		x = 0;
		while (x < map->sz)
		{
			if (map->mp[y][x] == '.')
			{
				set_point(&tetri->pt, x, y);
				if (check_fit(tetri, map))
					return (1);
			}
			++x;
		}
		++y;
	}
	return (0);
}

int		solve_map(t_tetri *tetri, int i, t_map *map)
{
	if (get_next_pos(tetri, map))
	{
		place_tetri(tetri, map, 1);
		if (!i)
			return (1);
		else if (solve_map(++tetri, --i, map))
			return (1);
		else
			place_tetri(tetri, map, 0);
	}
	return (0);
}

int		check_fit(t_tetri *tetri, t_map *map)
{
	int	j;
	int sz;

	j = -1;
	sz = map->sz - 1;
	while (++j < 4)
		if (tetri->coord[j].x + tetri->pt.x > sz
			|| tetri->coord[j].y + tetri->pt.y > sz
			|| map->mp[tetri->coord[j].y + tetri->pt.y]
				[tetri->coord[j].x + tetri->pt.x] != '.')
			return (0);
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
