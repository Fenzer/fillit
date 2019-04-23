/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:26:55 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/30 17:06:54 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../lib/libft.h"
# include <fcntl.h>

typedef struct	t_tetri {
	char	coord[4][2];
	char	order;
}				s_tetri;

char	*read_tetri(int fd);

int		check_tetri(char **grid);

#endif
