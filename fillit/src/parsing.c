/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:43:46 by liferrer          #+#    #+#             */
/*   Updated: 2019/01/29 20:12:49 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parsing(char **grid)
{
	int i;
	int pieces;

	i = 0;
	pieces = 0;
	while (*grid && pieces <= 4 && (*grid[i] == '.' || *grid[i] == '#' || *grid[i] == '\n'))
	{
		if (*grid[i] == '#')
			pieces++;
		i++;
	}
	if (*grid[i])
		return (0);
	while (--i && *grid[i] != '#')
		;
	pieces = 0;
	while (pieces != 6)
	{
		if (*grid[--i] == '#')
			pieces += 2;
		if (*grid[--i] == '#')

	}
	return (1);
}

//En comptant les \n dans la composition, il y a toujours 5 carac de differences entre deux # dans une forme sur plusieurs niveaux.
//Du coup on pourrait check +5 / -5 de chaque # pour trouver ceux qui sont colles sur d'autres niveaux.
//Juste avant on a secure qu'on trouvait bien 4 # dans le fichier donc il nous suffit de trouver deux # collees et ensuite on a juste a checker leur +5 / -5 ?
