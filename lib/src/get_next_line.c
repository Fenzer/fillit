/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 23:26:18 by fepinson          #+#    #+#             */
/*   Updated: 2019/06/15 18:20:16 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_split_line(char **line, char *s, char **rest)
{
	size_t	i[2];

	i[1] = ft_strlen(s);
	if ((i[0] = (size_t)(ft_strchr(s, '\n') - s)))
	{
		i[1] -= i[0];
		if (!(*line = ft_memalloc(i[0] + 1))
			|| !(*rest = ft_memalloc(i[1] + 1)))
			return (-1);
		i[1] = i[0];
		while (--i[0])
			(*line)[i[0]] = s[i[0]];
		*line[i[0]] = s[i[0]];
		while (s[++i[1]])
			(*rest)[i[0]++] = s[i[1]];
	}
	else
	{
		if (!(*line = ft_memalloc(1)))
			return (-1);
		if (i[1] && !(*rest = ft_strdup(s + 1)))
			return (-1);
	}
	free(s);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*rest[FOPEN_MAX];
	char			*buf;
	char			*s;
	int				rt;

	if (fd < 0 || fd > FOPEN_MAX || !line)
		return (-1);
	if (rest[fd] && ft_strchr(rest[fd], '\n'))
		return (ft_split_line(line, rest[fd], &rest[fd]));
	else if ((*line = rest[fd]))
		rest[fd] = NULL;
	else if (!(*line = ft_memalloc(1)))
		return (-1);
	if (!(buf = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	while (!ft_strchr(*line, '\n') && (rt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rt] = 0;
		s = *line;
		*line = ft_strjoin(*line, buf);
		free(s);
	}
	free(buf);
	rt = rt > 0 ? ft_split_line(line, *line, &rest[fd]) : rt;
	return (!rt && **line ? 1 : rt);
}
