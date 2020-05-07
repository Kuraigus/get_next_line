/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joguntij <joguntij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 00:32:33 by joguntij          #+#    #+#             */
/*   Updated: 2020/02/07 04:35:52 by joguntij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_join_and_free(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*dst;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(dst = (char*)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	free(s1);
	s1 = NULL;
	i = -1;
	while (s2[++i])
		dst[len1 + i] = s2[i];
	dst[len1 + i] = '\0';
	return (dst);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	i[2];

	if (s != NULL)
	{
		new_string = (char*)malloc(sizeof(char) * len + 1);
		if (!new_string)
			return (0);
		i[0] = start;
		i[1] = 0;
		while (i[0] < ft_strlen(s) && i[1] < len)
		{
			new_string[i[1]] = s[i[0]];
			i[1]++;
			i[0]++;
		}
		new_string[i[1]] = '\0';
		return (new_string);
	}
	return (NULL);
}

char			*ft_strdup(const char *s1)
{
	size_t		tam;
	char		*new_string;
	size_t		i;

	tam = ft_strlen(s1);
	new_string = (char*)malloc((sizeof(char) * tam) + 1);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (i < tam)
	{
		new_string[i] = s1[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

size_t			ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((char *)dst)[i] = ((char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
