/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:54:51 by fepinson          #+#    #+#             */
/*   Updated: 2019/04/24 14:30:23 by fepinson         ###   ########.fr       */
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

int		solve_map(t_tetri *tetri, int i, t_map *map)
{
	int j;

	j = 0;
	if (!check_fit(tetri + j))
		return (0);
	while (j < i)
	{
		if (check_fit(tetri + j, size))
		{
			get_next_pos(tetri + j, size, &p);
			j++;
		}
		else
	}
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
	set_point(&map->nxt, 0, 0);
	i = 0;
	while (i < sz)
		if (!(map->mp[i++] = (char *)ft_memalloc(sizeof(char *) * (sz + 1))))
			return (NULL);
}

int	solve(t_tetri *tetri, int i, int sz)
{
	t_map *map;

	if (!(map = init_map(sz)))
		return (1);
	while (!solve_map(t_tetri *tetri, i, map))
	{
		free_tab(map->mp);
		free(map);
		if (!(map = init_map(++sz)))
			return (1);
	}
	return (0);
}

int	main(int argc, const char *argv[])
{
	t_tetri	*tetri;
	int		fd;
	int		i;
	int		j;

	if (!(tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri) * 26)))
		return (free_msg_ret((void *)tetri, 42, "Error: Malloc failed."));
	i = -1;
	while (++i < 26 && 
		(j = read_load_tetri(fd = open(argv[1], O_RDONLY), tetri + i, i)))
		if (j < 0)
			return (free_msg_ret((void *)tetri, 42, "Error: Parsing failed."));
	if (i == 25 && read_load_tetri(fd, tetri + i, i))
		return (free_msg_ret((void *)tetri, 42, "Error: Parsing failed."));
	if (!!(solve(tetri, i, ft_sqrt(i * 4))))
		return (free_msg_ret((void *)tetri, 42, "Error: Solving failed."));
	return (free_msg_ret((void *)tetri, 0, NULL));
}
