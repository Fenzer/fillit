/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:26:55 by fepinson          #+#    #+#             */
/*   Updated: 2019/06/12 16:46:39 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./lib/libft.h"
# include <fcntl.h>

# define READ_SIZE 21

typedef struct	s_pt {
	int			x;
	int			y;
}				t_pt;

typedef	struct	s_map {
	int			sz;
	char		**mp;
}				t_map;

typedef struct	s_tetri {
	t_pt	pt;
	t_pt	coord[4];
	t_pt	mx;
	char	order;
}				t_tetri;

char	*read_tetri(int fd);

int		check_tetri(char *s);

void	normalize_coord(int min_y, int min_x, t_tetri *tetris);

int		check_tetri(char *s);

int		read_load_tetri(int fd, t_tetri *tetri, int i);

void	get_coord(char *str, t_tetri *tetris);

void	set_point(t_pt *pt, int x, int y);

int		get_next_pos(t_tetri *tetri, t_map *map);

int		check_fit(t_tetri *tetri, t_map *map);

#endif
