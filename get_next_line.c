/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:15:13 by caunhach          #+#    #+#             */
/*   Updated: 2023/05/21 15:03:30 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_buff(char *buff, char *src)
{
	char	*res;

	res = ft_strjoin(buff, src);
	free(buff);
	return (res);
}

char	*left_line(char *buff)
{
	size_t	len;
	char	*res;

	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (buff[len] == '\n')
		len++;
	if (len == 0)
		return (NULL);
	res = ft_calloc(len + 1, sizeof(char));
	len = 0;
	while (buff[len] && buff[len] != '\n')
	{
		res[len] = buff[len];
		len++;
	}
	if (buff[len] == '\n')
		res[len] = '\n';
	return (res);
}

char	*right_line(char *buff)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	size = ft_strlen(buff) -i + 1;
	res = ft_calloc(size, sizeof(char));
	i++;
	while (buff[i])
		res[j++] = buff[i++];
	free(buff);
	return (res);
}

char	*ft_read(int fd, char *buff)
{
	char	*res;
	int		size;

	size = 1;
	if (!buff)
		buff = ft_calloc(1, 1);
	res = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (size > 0)
	{
		size = read(fd, res, BUFFER_SIZE);
		if (size == -1)
		{
			free(res);
			return (NULL);
		}
		res[size] = '\0';
		buff = new_buff(buff, res);
		if (ft_strchr(res, '\n'))
			break ;
	}
	free(res);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = ft_read(fd, buff);
	if (!buff)
		return (NULL);
	line = left_line(buff);
	buff = right_line(buff);
	return (line);
}
