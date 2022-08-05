/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:23:02 by hamchur           #+#    #+#             */
/*   Updated: 2021/11/10 15:13:03 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_str
{
	char	*line;
	int		len;
	char	*tmp;
}t_str;

typedef struct s_gnl
{
	int			byte_read;
	char		*tmp;
	char		buff[BUFFER_SIZE + 1];
}t_gnl;

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_null(char **str);
void	ft_delete(char	**del);
char	*ft_strnew(size_t size);
char	*ft_str(char **raw_str);
char	*get_next_line(int fd);

#endif
