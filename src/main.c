/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:54:51 by fepinson          #+#    #+#             */
/*   Updated: 2019/04/23 15:36:56 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int free_return(void *p, int i)
{
	free(p);
	return (i);
}
int main(int argc, const char *argv[])
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
   while (--i != -1)
	{
		printf("tetri[%d] :\norder = %c\ncoord = ", i, tetri[i].order);
		j = -1;
		while (++j < 4)
			printf("{%d, %d}\n", tetri[i].coord[j][0], tetri[i].coord[j][1]);
	}
	return (free_return((void *)tetri, 0));
}
