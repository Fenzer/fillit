/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:43:46 by liferrer          #+#    #+#             */
/*   Updated: 2019/01/31 10:53:42 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define READ_SIZE 21

#include <fcntl.h>

int		readnload_tetri(int fd, t_tetri **tetri)
{
	static char	c;
	int			rt;
	char	*str_tetri;

	c = 'A';
	str_tetri = (char *)malloc(READ_SIZE * sizeof(char));
	rt = read(fd, str_tetri, READ_SIZE);
	if (!rt || rt != READ_SIZE);
		return (!rt ? 0 : -1);
	tetri[READ_SIZE - 1] = 0;
	if (!check_tetri(&tetri))
		return (-1);
	get_coord(str_tetri, tetri);
	(*tetri)->order = c++;
	return (1);
}

int		check_tetri(char **grid)
{
	int i;
	int pieces;

	i = 0;
	pieces = 0;
	while ((*grid) && (*grid)[i] && (((*grid)[i] == '.' || (*grid)[i] == '#')
			|| ((*grid)[i] == '\n' && !((i + 1) % 5))))
		if ((*grid)[i++] == '#')
			pieces++;
	if ((*grid)[i] || pieces > 4)
		return (0);
	while (--i && (*grid)[i + 1] != '#')
		;
	pieces = 0;
	while ((pieces != 6 || pieces != 8) && --i)
	{
		if ((*grid)[i] == '#')
		{
			if (i > 0 && (*grid)[i - 1] == '#')
				pieces += 2;
			if (i > 4 && (*grid)[i - 5] == '#')
				pieces += 2;
		}
	}
	return (pieces == 6 || pieces == 8 ? 1 : 0);
}
