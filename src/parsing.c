/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:43:46 by liferrer          #+#    #+#             */
/*   Updated: 2019/04/24 12:07:34 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../fillit.h"

void	set_min_max(t_tetri *tetri)
{
	int i;

	tetri->pt.x = 0;
	tetri->pt.y = 0;
	tetri->mx = tetri->coord[0];
	tetri->mn = tetri->coord[0];
	i = 4;
	while (i--)
	{
		if (tetri->coord[i].x > tetri->mx.x)
			tetri->mx.x = tetri->coord[i].x;
		if (tetri->coord[i].y > tetri->mx.y)
			tetri->mx.y = tetri->coord[i].y;
		if (tetri->coord[i].x < tetri->mn.x)
			tetri->mn.x = tetri->coord[i].x;
		if (tetri->coord[i].y > tetri->mn.y)
			tetri->mn.y = tetri->coord[i].y;
	}
}

void	get_coord(char *str, t_tetri *tetris)
{
	int i;
	int j;
	int	min_x;
	int min_y;

	i = -1;
	j = -1;
	min_x = 5;
	min_y = 5;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			tetris->coord[++j].y = i / 5;
			tetris->coord[j].x = i < 5 ? i : i % 5;
			if (tetris->coord[j].y < min_y)
				min_y = tetris->coord[j].y;
			if (tetris->coord[j].x < min_x)
				min_x = tetris->coord[j].x;
		}
	}
	while (j--)
		tetris->coord[j].x -= min_x;
	while (j < 4)
		tetris->coord[j++].y -= min_y;
}

int		read_load_tetri(int fd, t_tetri *tetri, int i)
{
	int			rt;
	char	str_tetri[READ_SIZE];

	i = read(fd, str_tetri, READ_SIZE);
	if (!i || (rt != READ_SIZE && rt != READ_SIZE - 1))
		return (!i ? 0 : -1);
	if (str_tetri[i - 1] == '\n')
		str_tetri[i - 1] = 0;
	else
		return (-1);
	if (!check_tetri(str_tetri))
		return (-1);
	get_coord(str_tetri, tetri);
	tetri->order = (char)(i + 'A');
	set_min_max(tetri);
	return (1);
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
	if (s[i] || j > 4)
		return (0);
	j = 0;
	while ((j != 6 || j != 8) && i)
		if (s[i--] == '#')
			s[i] == '#' || (i > 4 && s[i - 4]) ? j += 2 : 0;
	s[i] == '#' || (i > 4 && s[i - 4]) ? j += 2 : 0;
	return (j == 6 || j == 8 ? 1 : 0);
}
