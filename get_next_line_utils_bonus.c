/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:57:45 by thuynguy          #+#    #+#             */
/*   Updated: 2022/11/21 16:57:50 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dst;
	s = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src && dst < (src + len))
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2, int len)
{
	int		len1;
	int		ret;
	char	*res;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	ret = len1 + len;
	if (ret == 0)
		return (NULL);
	res = (char *) malloc(sizeof(*s1) * (ret + 1));
	if (!res)
		return (NULL);
	ft_memmove(res, s1, len1);
	ft_memmove(&res[len1], s2, len);
	res[ret] = '\0';
	if (s1)
		free(s1);
	return (res);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;
	char	*ptr;

	if (!src)
		return (NULL);
	i = ft_strlen(src);
	str = (char *) malloc(sizeof(*src) * (i + 1));
	if (!str)
		return (NULL);
	ptr = str;
	ft_memmove(ptr, src, i);
	ptr[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*p;

	if (!s)
		return (NULL);
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	p = sub;
	ft_memmove(p, s + start, len);
	p[len] = '\0';
	return (sub);
}
