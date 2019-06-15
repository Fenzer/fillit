/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:54:51 by fepinson          #+#    #+#             */
/*   Updated: 2019/06/15 20:09:33 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void	set_point(t_pt *pt, int x, int y)
{
	pt->x = x;
	pt->y = y;
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

int		parse(t_tetri *tetri, int fd, int *i)
{
	int		j;
	char	s[1];

	*i = 0;
	while (42)
	{
		if (!(j = read_load_tetri(fd, tetri + *i, *i)))
			break ;
		else if (j != 1)
			return (0);
		++*i;
	}
	if (--*i > 26 || read(fd, s, 1))
		return (0);
	return (1);
}

int		main(int argc, const char *argv[])
{
	t_tetri	*tetri;
	char	**mp;
	int		fd;
	int		i;

	if (argc != 2)
		return (ft_free_msg_ret(NULL, "Usage : fillit\t[FILE]", 42));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_free_msg_ret(NULL, "error : can't open file.", 42));
	if (!(tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri) * 26)))
		return (ft_free_msg_ret((void *)tetri, "error: malloc failed.", 42));
	if (!parse(tetri, fd, &i))
		return (ft_free_msg_ret((void *)tetri, "error", 42));
	if (!(mp = solve(tetri, i, ft_rsqrt((i + 1) * 4))))
		return (ft_free_msg_ret((void *)tetri, "error : solving failed.", 42));
	i = -1;
	while (mp[++i])
		ft_putendl(mp[i]);
	ft_freetab(mp);
	close(fd);
	return (ft_free_msg_ret((void *)tetri, NULL, 0));
}
