/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:43:46 by liferrer          #+#    #+#             */
/*   Updated: 2019/01/30 17:06:52 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

char	*read_tetri(int fd)
{
	static char c;
	char *tetri = malloc(21);

	c = 'A';
	read(fd ,tetri, 21);
	tetri[20] = 0;
	return (tetri);
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

int main(int ac, char **av)
{
	s_tetri tetri[26];
	int fd = open(av[1], O_RDONLY);
	char *str = read_tetri(fd);

	printf("%d\n", check_tetri(&str));
	free(str);
}
