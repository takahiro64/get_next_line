/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:42:20 by thine             #+#    #+#             */
/*   Updated: 2024/11/02 19:13:50 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

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
	return (dst);
}

char	*ft_strdup(char *s1, size_t capa)
{
	char	*s2;

	s2 = NULL;
	s2 = (char *)malloc((sizeof(char)) * capa);
	if (!s2)
		return (NULL);
	ft_memcpy (s2, s1, capa / 2);
	free (s1);
	return (s2);
}

int	ft_realloc(char **str, size_t capa)
{
	char	*tmp;

	tmp = (char *)malloc((sizeof(char)) * capa * 2);
	if (!tmp)
	{
		*str = NULL;
		return (capa);
	}
	ft_memcpy (tmp, *str, capa);
	free (*str);
	*str = malloc(sizeof(char) * capa * 2);
	ft_memcpy (*str, tmp, capa);
	free (tmp);
	return (capa * 2);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pmem;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size && count >= SIZE_MAX / size)
		return (NULL);
	pmem = malloc(count * size);
	if (!pmem)
		return (NULL);
	ft_bzero(pmem, count * size);
	return (pmem);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n != 0)
	{
		*ptr++ = 0;
		n--;
	}
}
