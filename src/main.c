/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:54:51 by fepinson          #+#    #+#             */
/*   Updated: 2019/04/23 18:41:47 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int	free_return(void *p, int i)
{
	free(p);
	return (i);
}

int	solve(t_tetri *tetri, int i)
{
	int	x;
	int	y;
	int	sz;

	sz = i;
	x = 0;
	y = 0;
	while (i >= 0)
	{
		x += get_max(tetri + i, 0);
		y += get_max(tetri + i, 1);
		--i;
	}
	i = sz;
	sz = x > y ? x : y;
	while ((y = find_overlap(tetri, i)))
	{
		x = i + 1;
		while (--x >= 0)
			move_tetris(sztetri[x]);
	}
}

int	main(int argc, const char *argv[])
{
	t_tetri	*tetri;
	int		fd;
	int		i;
	int		j;

	fd = open(argv[1], O_RDONLY);
	if (!(tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri) * 26)))
		return (free_return((void *)tetri, 42));
	i = -1;
	while (++i < 26 && (j = read_load_tetri(fd, tetri + i, i)))
		if (j < 0)
			return (free_return((void *)tetri, 42));
	if (i == 25 && read_load_tetri(fd, tetri + i, i))
		return (free_return((void *)tetri, 42));
	solve(tetri, i);
	return (free_return((void *)tetri, 0));
}
