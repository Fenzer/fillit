/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:43:46 by liferrer          #+#    #+#             */
/*   Updated: 2019/04/19 18:05:21 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../fillit.h"

void	normalize_coord(int min_y, int min_x, t_tetri **tetris)
{
	int i;

	i = 0;
	while (i < 4)
	{
		(*tetris)->coord[i][0] -= min_y;
		(*tetris)->coord[i][1] -= min_x;
		i++;
	}
}

void	get_coord(char **str, t_tetri **tetris)
{
	int i;
	int j;
	int	min_x;
	int min_y;

	i = 0;
	j = 0;
	min_x = 5;
	min_y = 5;
	while ((*str)[i])
	{
		if ((*str)[i] == '#')
		{
			(*tetris)->coord[j][0] = i / 5;
			(*tetris)->coord[j][1] = i < 5 ? i : i % 5;
			if ((*tetris)->coord[j][0] < min_y)
				min_y = (*tetris)->coord[j][0];
			if ((*tetris)->coord[j][1] < min_x)
				min_x = (*tetris)->coord[j][1];
			j++;
		}
		i++;
	}
	normalize_coord(min_y, min_x, tetris);
}

int		read_load_tetri(int fd, t_tetri **tetri)
{
	static char	c;
	int			rt;
	char	*str_tetri;

	c = 'A';
	str_tetri = (char *)malloc(READ_SIZE * sizeof(char));
	rt = read(fd, str_tetri, READ_SIZE);
	if (!rt || rt != READ_SIZE)
		return (!rt ? 0 : -1);
	tetri[READ_SIZE - 2] = 0;
	if (!check_tetri(str_tetri))
		return (-1);
	get_coord(&str_tetri, tetri);
	(*tetri)->order = c++;
	return ((int) (c - 'A'));
}

int		check_tetri(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i]
			&& (s[i] == '.' || s[i] == '#' || (s[i] == '\n' && !((i + 1) % 5))))
		if (s[i++] == '#')
			j++;
	if (!s[i] || j > 4)
		return (0);
	j = 0;
	while ((j != 6 || j != 8) && i)
		if (s[i--] == '#')
			s[i] == '#' || (i > 4 && s[i - 4]) ? j += 2 : 0;
	return (j == 6 || j == 8 ? 1 : 0);
}
