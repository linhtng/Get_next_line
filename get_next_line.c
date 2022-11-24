/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:01:38 by thuynguy          #+#    #+#             */
/*   Updated: 2022/11/15 15:48:18 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

static char	*detect_line(int fd, char *storage)
{
	char	*buf;
	int		ret;

	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while (ft_strchr(storage, '\n') == NULL && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		if (ret > 0)
			storage = ft_strjoin(storage, buf, ret);
	}
	free(buf);
	return (storage);
}

static char	*get_line(char *storage)
{
	int		i;
	char	*line;
	char	*endl;

	if (!storage)
		return (NULL);
	endl = ft_strchr(storage, '\n');
	if (!endl)
		return (ft_strdup(storage));
	i = (int)(endl - storage);
	line = ft_substr(storage, 0, i + 1);
	return (line);
}

static char	*storage_update(char *storage, size_t left_storage, size_t linelen)
{
	char	*new_storage;

	if (!storage)
		return (NULL);
	if (left_storage == 0)
	{
		free(storage);
		return (NULL);
	}
	new_storage = ft_substr(storage, linelen, left_storage);
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;
	size_t		linelen;
	size_t		left_storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = detect_line(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line(storage);
	if (!line)
		return (NULL);
	linelen = ft_strlen(line);
	left_storage = ft_strlen(storage) - linelen;
	storage = storage_update(storage, left_storage, linelen);
	if (!storage && left_storage != 0)
		return (NULL);
	return (line);
}
