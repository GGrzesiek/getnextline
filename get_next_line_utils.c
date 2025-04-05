/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:06:58 by ggrzesiek         #+#    #+#             */
/*   Updated: 2025/04/05 07:10:15 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if(!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*big;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if(!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if(!s2)
		return (s1);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	big = (char *)malloc(size);
	if (!big)
	{
		free((char *)s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		big[i] = s1[i];
	j = -1;
	while(s2[++j])
	big[i + j] = s2[j];
	big[i + j] = '\0';
	free(s1);
	return (big);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
