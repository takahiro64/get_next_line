/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:11:11 by thine             #+#    #+#             */
/*   Updated: 2024/11/04 12:17:43 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdint.h>


typedef struct s_list
{
	char		buf[BUFFER_SIZE];
	char		*bufp;
	int		n;
	int		fld;
	struct s_list	*next;
}		t_list;

typedef struct s_line_reader
{
	char	*str;
	size_t	len;
	size_t	capa;
	int	c;
}	t_line_reader;

char	*get_next_line(int fd);
char	*ft_strdup(char *str, size_t capa);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int	ft_getc(int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int	ft_realloc(char **str, size_t capa);

#endif
