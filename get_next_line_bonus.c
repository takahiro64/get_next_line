/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:01:31 by thine             #+#    #+#             */
/*   Updated: 2024/11/04 13:44:34 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*del_buf(char *buf)
{
	char	*tmp;
	int	i;

	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
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
	int	i;
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


char	*read_file(char *buf, int fd)
{
	char	*res;
	int	byte_read;

	if (buf && ft_strchr(buf, '\n'))
		return (buf);
	if (buf)
		res = ft_strjoin(NULL, buf, ft_strlen(buf));
	while (1)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
		{
			free(res);
			return NULL;
		}
		byte_read = read(fd, buf, BUFFER_SIZE);
		res = ft_strjoin(res, buf, byte_read);
		printf("flag in read_file\n");
		if (!res)
			return (NULL);
		if (ft_strchr(buf, '\n') || byte_read == 0)
			break ;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buf[5000];
	char		*line;

	printf("gnl start\n");
	buf[fd] = read_file(buf[fd], fd);
	if (!buf[fd])
		return (NULL);
	line = read_line(buf[fd]);
	buf[fd] = del_buf(buf[fd]);
	return (line);
}
