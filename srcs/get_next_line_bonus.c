/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joguntij <joguntij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 23:46:16 by joguntij          #+#    #+#             */
/*   Updated: 2020/02/07 04:33:57 by joguntij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_find_char(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] != c)
		return (-1);
	return (i);
}

int				get_line(char **str, char **line, int i)
{
	int		len;

	*line = ft_substr(*str, 0, i);
	i++;
	len = ft_strlen(*str + i) + 1;
	ft_memmove(*str, *str + i, len);
	if (*str && *str[0] == '\0')
	{
		free(*str);
		*str = NULL;
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char		*str[OPEN_MAX];
	char			buff[BUFFER_SIZE + 1];
	int				ret;
	int				i;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (str[fd] && (i = ft_find_char(str[fd], '\n')) != -1)
		return (get_line(&str[fd], line, i));
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str[fd] = ft_join_and_free(str[fd], buff);
		if ((i = ft_find_char(str[fd], '\n')) != -1)
			return (get_line(&str[fd], line, i));
	}
	if (str[fd])
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (ret);
	}
	*line = ft_strdup("");
	return (ret);
}
