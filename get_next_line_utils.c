/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:52:10 by caunhach          #+#    #+#             */
/*   Updated: 2023/05/21 16:04:12 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	n;
	size_t	i;

	i = 0;
	if (nmemb >= SIZE_MAX || size >= SIZE_MAX || size * nmemb >= SIZE_MAX)
		return (NULL);
	n = nmemb * size;
	ptr = (unsigned char *)malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	while (n--)
		*((unsigned char *)ptr + i++) = 0;
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*dest;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (*s1)
		*dest++ = *s1++;
	while (*s2)
		*dest++ = *s2++;
	*dest = '\0';
	return (dest - len);
}

size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}
