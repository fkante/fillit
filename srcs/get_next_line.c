/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:04:57 by fkante            #+#    #+#             */
/*   Updated: 2019/05/23 15:51:00 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				strrest_with_newline(char **line, char **str_rest);
ssize_t			read_buffer(const int fd, char **line, char **str_rest);

int		strrest_with_newline(char **line, char **str_rest)
{
	char	*newline_position;
	char	*str_after_newline;

	newline_position = NULL;
	str_after_newline = NULL;
	if (*str_rest == NULL)
		return (0);
	newline_position = ft_strchr(*str_rest, '\n');
	if (newline_position == NULL)
	{
		*line = ft_strdup(*str_rest);
		ft_strdel(str_rest);
		return (0);
	}
	if (*(newline_position + 1) != '\0')
		str_after_newline = ft_strdup(newline_position + 1);
	*newline_position = '\0';
	*line = ft_strdup(*str_rest);
	ft_strdel(str_rest);
	*str_rest = str_after_newline;
	return (1);
}

ssize_t	read_buffer(const int fd, char **line, char **str_rest)
{
	char		buff[BUFF_SIZE + 1];
	char		*newline_position;
	char		*leaks;
	ssize_t		read_return;

	while ((read_return = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_return] = '\0';
		leaks = *line;
		if ((newline_position = ft_strchr(buff, '\n')) == NULL)
		{
			*line = ft_strjoin(*line, buff);
			ft_strdel(&leaks);
			continue ;
		}
		if (*(newline_position + 1) != '\0')
			*str_rest = ft_strdup(newline_position + 1);
		*newline_position = '\0';
		*line = ft_strjoin(*line, buff);
		ft_strdel(&leaks);
		return (1);
	}
	if (read_return == -1)
		return (-1);
	return ((*line == NULL && *str_rest == NULL) ? 0 : 1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str_rest;
	
	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (strrest_with_newline(line, &str_rest) == 1)
		return (1);
	return ((int)read_buffer(fd, line, &str_rest));
}
