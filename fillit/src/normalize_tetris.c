/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_tetris.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:27:53 by liferrer          #+#    #+#             */
/*   Updated: 2019/02/04 12:28:03 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	normalize_tetris(t_tetris **tetris)
{
	int i;
	int min_y;
	int min_x;

	i = 0;
	min_y = 5;
	min_x = 5;
	while (i < 4)
	{
		if ((*tetris)->coord[i][0] < min_y)
			min_y = (*tetris)->coord[i][0];
		if ((*tetris)->coord[i][1] < min_x)
			min_x = (*tetris)->coord[i][1];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*tetris)->coord[i][0] -= min_y;
		(*tetris)->coord[i][1] -= min_x;
		i++;
	}
}
