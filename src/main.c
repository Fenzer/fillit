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

int		solve_square(t_tetri *tetri, int i, int size)
{

}

int	free_return(void *p, int i)
{
	free(p);
	return (i);
}

int	solve(t_tetri *tetri, int i, int sz)
{
	return (0);
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
	solve(tetri, i, ft_sqrt(i * 4));
	return (free_return((void *)tetri, 0));
}
