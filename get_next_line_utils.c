/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:04:08 by thine             #+#    #+#             */
/*   Updated: 2024/11/05 16:04:10 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*chr;

	ptr = (unsigned char *)dst;
	chr = (unsigned char *)src;
	if (src || dst)
	{
		while (n > 0)
		{
			*ptr++ = *chr++;
			n--;
		}
	}
	*ptr = '\0';
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (*s == (char)c)
		return ((char *)s);
	while (*s)
	{
		s++;
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}

void	*ft_realloc(char *str, size_t capa)
{
	char	*tmp;

	if (!str)
	{
		str = malloc(capa);
		return (str);
	}
	tmp = (char *)malloc(capa);
	if (!tmp)
	{
		free(str);
		return (NULL);
	}
	ft_memcpy(tmp, str, ft_strlen(str));
	free(str);
	str = malloc(capa);
	if (!str)
	{
		free(tmp);
		return (NULL);
	}
	ft_memcpy(str, tmp, ft_strlen(tmp));
	free(tmp);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*pmem;
	unsigned char	*ptr;
	size_t			n;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size && count >= SIZE_MAX / size)
		return (NULL);
	pmem = malloc(count * size);
	if (!pmem)
		return (NULL);
	n = count * size;
	ptr = (unsigned char *)pmem;
	while (n != 0)
	{
		*ptr++ = 0;
		n--;
	}
	return (pmem);
}
