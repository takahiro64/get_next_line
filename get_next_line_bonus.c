/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:01:31 by thine             #+#    #+#             */
/*   Updated: 2024/11/07 13:50:40 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*del_buf(char *buf)
{
	char	*tmp;
	size_t	i;

	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	if (i == ft_strlen(buf))
	{
		free(buf);
		return (ft_calloc(1, 1));
	}
	tmp = malloc(ft_strlen(buf) - i + 1);
	if (!tmp)
	{
		free(buf);
		return (NULL);
	}
	ft_memcpy(tmp, buf + i, ft_strlen(buf) - i);
	free(buf);
	return (tmp);
}

char	*read_line(char *buf)
{
	int		i;
	char	*line;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, buf, i);
	line[i] = '\0';
	return (line);
}

char	*read_file(char *res, int fd)
{
	char	*buf;
	int		byte_read;

	if (!res)
	{
		res = ft_calloc(1, 1);
		if (!res)
			return (NULL);
	}
	while (1)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
		{
			free(res);
			return (NULL);
		}
		byte_read = read(fd, buf, BUFFER_SIZE);
		res = strcat_free(res, buf, byte_read);
		if (!res && byte_read != 0)
			return (NULL);
		if (ft_strchr(res, '\n') || byte_read == 0)
			break ;
	}
	return (res);
}

char	*strcat_free(char *res, char *buf, int buf_size)
{
	int	res_size;

	if (buf_size < 0)
	{
		free(res);
		free(buf);
		return (NULL);
	}
	if (buf_size == 0)
	{
		free(buf);
		if (*res)
			return (res);
		free(res);
		return (NULL);
	}
	res = ft_realloc(res, (res_size = ft_strlen(res)) + buf_size + 1);
	if (!res)
	{
		free(buf);
		return (NULL);
	}
	ft_memcpy(res + res_size, buf, buf_size);
	free(buf);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buf[5000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buf[fd] = read_file(buf[fd], fd);
	if (!buf[fd])
		return (NULL);
	line = read_line(buf[fd]);
	buf[fd] = del_buf(buf[fd]);
	if (!buf[fd])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
