/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:51:32 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/04/05 10:57:47 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

static int process_buffer(char **stash, char *buff, int bytes_read)
{
	buff[bytes_read] = '\0';
	if(bytes_read > 0)
	{
		*stash = ft_strjoin(*stash, buff);
		if(!*stash)
			return (0);
	}
	return (1);
}
char *ft_read_to_stash(int fd, char *stash)
{
	char *buff;
	int bytes_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		if(!process_buffer(&stash, buff,bytes_read))
		{
			free(buff);
			return (NULL);
		}
		if(bytes_read == 0 || ft_strchr(buff,'\n'))
			break;
	}
	free(buff);
	return (stash);
}
char *ft_get_line(char *stash)
{
	int i;
	char *line;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char *ft_update_stash(char *stash)
{
	int i;
	int j;
	char *new_stash;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc((ft_strlen(stash) - i) * sizeof(char));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[++i])
		new_stash[j++] = stash[i];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char *get_next_line(int fd)
{
	static char *stash = NULL;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_update_stash(stash);
	return (line);
}
