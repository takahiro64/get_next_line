/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:22:29 by thine             #+#    #+#             */
/*   Updated: 2024/11/02 19:07:29 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	t_line_reader	lr;

	lr.len = 0;
	lr.capa = 1024;
	lr.str = ft_calloc(lr.capa, sizeof(char));
	lr.c = ft_getc(fd);
	while (lr.c != '\n')
	{
		if (lr.c == EOF)
		{
			if (*(lr.str))
				return (lr.str);
			free(lr.str);
			return (NULL);
		}
		if (++lr.len + 1 > lr.capa)
		{
			//lr.capa *= 2;
			//lr.str = ft_strdup(lr.str, lr.capa);
			lr.capa = ft_realloc(&lr.str, lr.capa);
		}
		lr.str[lr.len - 1] = lr.c;
		lr.c = ft_getc(fd);
	}
	lr.str[lr.len] = '\n';
	lr.str[lr.len + 1] = '\0';
	return (lr.str);
}

int	ft_getc(int fd)
{
	static t_list	buf;

	if (buf.n == 0)
	{
		buf.n = read(fd, buf.buf, BUFFER_SIZE);
		buf.bufp = buf.buf;
	}
	if (--buf.n >= 0)
		return ((unsigned char) *(buf.bufp++));
	return (EOF);
}
