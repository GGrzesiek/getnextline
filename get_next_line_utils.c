/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:13:42 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/04/05 13:13:43 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
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
	char	*big;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (s1);
	big = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!big)
		return (cleanup(s1, NULL, 1));
	i = -1;
	j = -1;
	while (s1[++i])
		big[i] = s1[i];
	while (s2[++j])
		big[i + j] = s2[j];
	big[i + j] = '\0';
	free(s1);
	return (big);
}

char	*cleanup(char *stash, char *buffer, int mode)
{
	if (mode == 1)
		free(stash);
	if (mode == 2)
		free(buffer);
	if (mode == 3)
	{
		free(stash);
		free(buffer);
	}
	return (NULL);
}
