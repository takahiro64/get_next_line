/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:16:55 by thine             #+#    #+#             */
/*   Updated: 2024/11/04 13:24:29 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H 
# define GET_NEXT_LINE_BONUS_H 

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdint.h>
#include <stddef.h>

char	*del_buf(char *buf);
char	*read_line(char *buf);
char	*ft_strjoin(char *res, char *buf, int buf_size);
char	*read_file(char *buf, int fd);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int	ft_realloc(char **str, size_t capa);

#endif