/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:43:46 by liferrer          #+#    #+#             */
/*   Updated: 2019/06/12 19:11:11 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../fillit.h"

void	set_max(t_tetri *tetri)
{
	int i;

	tetri->pt.x = 0;
	tetri->pt.y = 0;
	tetri->mx = tetri->coord[0];
	i = 4;
	while (i--)
	{
		if (tetri->coord[i].x > tetri->mx.x)
			tetri->mx.x = tetri->coord[i].x;
		if (tetri->coord[i].y > tetri->mx.y)
			tetri->mx.y = tetri->coord[i].y;
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
	while (j >= 0)
		tetris->coord[j--].x -= min_x;
	while (j < 4)
		tetris->coord[j++].y -= min_y;
}

int		read_load_tetri(int fd, t_tetri *tetri, int i)
{
	int			rt;
	char	str_tetri[READ_SIZE];

	if (fd < 0)
		return (0);
	rt = read(fd, str_tetri, READ_SIZE);
	if ((rt != READ_SIZE && rt != READ_SIZE - 1))
		return (0);
	if (str_tetri[rt - 1] == '\n')
		str_tetri[rt - 1] = 0;
	else
		return (0);
	if (!check_tetri(str_tetri))
		return (0);
	get_coord(str_tetri, tetri);
	tetri->order = (char)(i + 'A');
	set_max(tetri);
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
