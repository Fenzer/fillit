/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overlap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:40:40 by liferrer          #+#    #+#             */
/*   Updated: 2019/02/04 17:39:15 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int	check_overlap(t_tetri *forme1, t_tetri *forme2)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((*forme1).coord[i][0] == (*forme2).coord[i][0]
			 && (*forme1).coord[i][1] == (*forme2).coord[i][1]) 
			return (0);
		else
			i++;
	}
	return (1);
}

int	main(void)
{
	t_tetri	forme1;
	t_tetri forme2;

	forme1.coord[0][0] = 0;
	forme1.coord[0][1] = 1;
	forme1.coord[1][0] = 1;
	forme1.coord[1][1] = 0;
	forme1.coord[2][0] = 1;
	forme1.coord[2][1] = 1;
	forme1.coord[3][0] = 1;
	forme1.coord[3][1] = 2;

	forme2.coord[0][0] = 0;
	forme2.coord[0][1] = 3;
	forme2.coord[1][0] = 1;
	forme2.coord[1][1] = 3;
	forme2.coord[2][0] = 2;
	forme2.coord[2][1] = 3;
	forme2.coord[3][0] = 3;
	forme2.coord[3][1] = 3;

	check_overlap(&forme1, &forme2);
	return (0);
}
