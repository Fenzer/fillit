/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:26:55 by fepinson          #+#    #+#             */
/*   Updated: 2019/10/02 22:53:46 by fepinson         ###   ########.fr       */
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
	char	**tetri;
	t_pt	mx;
	t_pt	mn;
	char	order;
}				t_tetri;

int				check_tetri(char *s);

int				check_fit(t_tetri *tetri, t_map *map, int x, int y);

void			normalize_coord(int min_y, int min_x, t_tetri *tetris);

int				read_load_tetri(int *fd, t_tetri *tetri, int i);

void			get_coord(char *str, t_tetri *tetris);

void			set_point(t_pt *pt, int x, int y);

int				get_next_pos(t_tetri *tetri, t_map *map);

void			place_tetri(t_tetri *tetri, t_map *map, int mode);

int				solve_map(t_tetri *tetri, int i, t_map *map);

char			**solve(t_tetri *tetri, int i, int sz);

t_map			*init_map(int sz);

void			set_point(t_pt *pt, int x, int y);

int				parse(t_tetri *tetri, const char *p, int *i);

char			**get_tetri(t_tetri *tetri);

int				try_tetri(t_tetri *tetri, t_map *map, int x, int y);

#endif
