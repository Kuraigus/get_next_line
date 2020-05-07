/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joguntij <joguntij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 23:44:40 by joguntij          #+#    #+#             */
/*   Updated: 2020/02/07 04:36:31 by joguntij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_join_and_free(char *s1, char *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
