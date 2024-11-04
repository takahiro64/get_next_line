/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:06:29 by thine             #+#    #+#             */
/*   Updated: 2024/11/04 13:49:23 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

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
	if (*s == (char)c)
		return ((char *) s);
	while (*s)
	{
		s++;
		if (*s == (char) c)
			return ((char *)s);
	}
	return (NULL);
}

int	ft_realloc(char **str, size_t capa)
{
	char	*tmp;

	if (!*str)
	{
		*str = malloc(capa);
		return (capa);
	}
	printf("realloc start\n");
	tmp = (char *)malloc(capa);
	if (!tmp)
	{
		*str = NULL;
		return (capa);
	}
	printf("flag1\n");
	ft_memcpy (tmp, *str, ft_strlen(*str));
	printf("flag2\n");
	free (*str);
	printf("flag3\n");
	*str = malloc(capa);
	ft_memcpy (*str, tmp, ft_strlen(*str));
	printf("flag4\n");
	free (tmp);
	return (capa);
}

char	*ft_strjoin(char *res, char *buf, int buf_size)
{
	int	res_size;

	printf("strjoin start\n");
	if (buf_size < 0)
	{
		free(res);
		free(buf);
		return (NULL);
	}
	printf("flag1\n");
	res_size = ft_strlen(res);
	ft_realloc(res, res_size + buf_size + 1);
	printf("flag2\n");
	if (!res)
	{
		free(buf);
		return (NULL);
	}
	ft_memcpy(res + res_size, buf, buf_size);	
	printf("flag3\n");
	res[ft_strlen(res)] = '\0';
	free(buf);
	printf("flag4\n");
	return (res);
}