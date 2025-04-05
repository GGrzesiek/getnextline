/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:42:05 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/04/05 10:34:59 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char *get_next_line(int fd);
char *ft_read_to_stash(int fd, char *stash);
char *ft_get_line(char *stash);
char *ft_update_stash(char *stash);
char *ft_strjoin(char  *s1, char  *s2);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
void cleanup(char *stash, char *buffer,int mode);
#endif