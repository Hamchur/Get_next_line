/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:22:49 by hamchur           #+#    #+#             */
/*   Updated: 2021/11/10 15:57:27 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_null(char	**str)
{
	if ((*str)[0] == '\0')
	{
		ft_delete(str);
		return (1);
	}
	return (0);
}

void	ft_delete(char **de)
{
	if (de)
	{
		free(*de);
		*de = NULL;
	}
}

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	str[size] = '\0';
	return (str);
}

char	*ft_str(char **raw_str)
{
	t_str	data;

	data.len = 0;
	if (ft_null(raw_str) == 1)
		return (NULL);
	while ((*raw_str)[data.len] && (*raw_str)[data.len] != '\n')
		data.len++;
	if ((*raw_str)[data.len] == '\n')
	{
		data.line = ft_substr(*raw_str, 0, data.len + 1);
		data.tmp = ft_strdup(&(*raw_str)[data.len + 1]);
		free(*raw_str);
		if (data.tmp)
		{
			*raw_str = ft_strdup(data.tmp);
			free(data.tmp);
		}
	}
	else
	{
		data.line = ft_strdup(*raw_str);
		ft_delete(raw_str);
	}
	return (data.line);
}

char	*get_next_line(int fd)
{
	t_gnl		data;
	static char	*raw_str;

	if (read(fd, data.buff, 0) == -1)
		return (NULL);
	if (raw_str == NULL)
		raw_str = ft_strnew(0);
	while (ft_strchr(raw_str, '\n') == NULL || ft_strchr(raw_str, '\0') == NULL)
	{
		data.byte_read = read(fd, data.buff, BUFFER_SIZE);
		data.buff[data.byte_read] = '\0';
		if (data.byte_read == 0)
			return (ft_str(&raw_str));
		data.tmp = ft_strjoin(raw_str, data.buff);
		free(raw_str);
		raw_str = ft_strdup(data.tmp);
		free(data.tmp);
	}
	return (ft_str(&raw_str));
}
