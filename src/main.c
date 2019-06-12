/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:54:51 by fepinson          #+#    #+#             */
/*   Updated: 2019/06/12 19:20:38 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		ft_sqrt(int n)
{
	int	large;
	int	small;

	if (n < 0)
		return (0);
	if (n < 2)
		return (n);
	else
	{
		small = ft_sqrt(n >> 2) << 1;
		large = small + 1;
		if (small * large > n)
			return (small);
		else
			return (large);
	}
}

void	place_tetri(t_tetri *tetri, t_map *map, int mode)
{
	int i;

	i = 4;
	while (--i != -1)
		mode ? map->mp[tetri->coord[i].y + tetri->pt.y]
			[tetri->coord[i].x + tetri->pt.x] = tetri->order : '.';
}

int		get_next_pos(t_tetri *tetri, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->sz - 1)
	{
		j = 0;
		while (j < map->sz - 1)
		{
			if (map->mp[i][j] == '.' && check_fit(tetri, map))
			{
				set_point(&tetri->pt, j, i);
				return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

int		solve_map(t_tetri *tetri, int i, t_map *map)
{
	int x;
	int y;

	y = -1;
	while (++y + tetri->mx.y < map->sz && (x = -1))
	{
		while (++x + tetri->mx.x < map->sz)
		{
			if (get_next_pos(tetri, map))
			{
				place_tetri(tetri, map, 1);
				if (!i)
					return (1);
				if (i && solve_map(++tetri, --i, map))
					return (1);
				else
					place_tetri(tetri, map, 0);
			}
		}
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


void	set_point(t_pt *pt, int x, int y)
{
	pt->x = x;
	pt->y = y;
}

int	free_msg_ret(void *p, int i, char *s)
{
	if (s)
		ft_putendl(s);
	if (p)
		free(p);
	return (i);
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

char	**solve(t_tetri *tetri, int i, int sz)
{
	t_map	*map;
	char	**mp;

	if (!(map = init_map(sz)))
		return (NULL);
	while (!solve_map(tetri, i, map))
	{
		ft_freetab(map->mp);
		free(map);
		if (!(map = init_map(++sz)))
			return (NULL);
	}
	mp = map->mp;
	free(map);
	return (mp);
}

int	main(int argc, const char *argv[])
{
	t_tetri	*tetri;
	char	**mp;
	int		fd;
	int		i;

	if (argc != 2)
		return (free_msg_ret(NULL, 42, "Usage : fillit\t[FILE]"));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (free_msg_ret(NULL, 42, "Can't open file"));
	if (!(tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri) * 26)))
		return (free_msg_ret((void *)tetri, 42, "Error: Malloc failed."));
	i = 0;
	while (read_load_tetri(fd,  tetri + i, i))
		++i;
	if (--i > 26)
		return (free_msg_ret((void *)tetri, 42, "error"));
	if (!(mp = solve(tetri, i, ft_sqrt((i + 1) * 4))))
		return (free_msg_ret((void *)tetri, 42, "Can't solve."));
	i = -1;
	while (mp[++i])
		ft_putstr(mp[i]);
	ft_freetab(mp);
	close(fd);
	return (free_msg_ret((void *)tetri, 0, NULL));
}
