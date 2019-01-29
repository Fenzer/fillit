/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 23:26:18 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/25 11:59:46 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_next_line(const int fd, char **line)
{
	static	char	left[BUFF_SIZE + 1];
	char			buff[BUFF_SIZE + 1];
	char			*s1;
	char			*s2;
	int				rt;

	if (fd < 0 || fd > OPEN_MAX || !line || !(*line = !*left
				? (char *)ft_memalloc(sizeof(char)) : ft_strdup(left)))
		return (-1);
	ft_memset(buff, 0, BUFF_SIZE + 1);
	ft_memset(left, 0, BUFF_SIZE + 1);
	while (!ft_strchr(*line, '\n') && (rt = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rt] = 0;
		*line = ft_dyncat(*line, buff, ft_strlen(*line) + ft_strlen(buff), 1);
	}
	if (!rt)
		return (line && *line && **line ? 1 : 0);
	if ((int)(s1 = ft_strchr(*line, '\n') + 1) != 1)
		ft_strncpy(left, s1, ft_strlen(s1));
	s2 = *line;
	*line = (int)s1 == 1 || s1 == s2 ? ft_strdup("")
		: ft_strndup(s2, (size_t)(s1 - s2) - 1);
	free(s2);
	return (rt == -1 ? rt : 1);
}
