/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:54:51 by fepinson          #+#    #+#             */
/*   Updated: 2019/04/23 13:02:38 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fillit.h"

int main(int argc, const char *argv[])
{
	t_tetri	*tetri;
	int		fd;
	int		i;
	int		j;

	fd = open(argv[1], O_RDONLY);
	if (!(tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri) * 26)))
		return (42);
	i = -1;
	while (++i < 26)
		if (!(i = read_load_tetri(fd,tetri[0])))
			return (42);
   while (--i != -1)
	{
		printf("tetri[%d] :\norder = %ci\ncoord = ", i, tetri->order);
		j = -1;
		while (++j < 4)
			printf("{%d, %d}\n", tetri->coord[j][0], tetri->coord[j][1]);
	}
	free(tetri);
	return (0);
}
