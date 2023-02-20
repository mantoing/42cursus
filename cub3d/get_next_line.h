/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:51:30 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/20 17:12:51 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		check_newline(char *line);
char	*get_newline(char **line, int rsize);
int		get_next_line(int fd, char **line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_error(char **st);
int		chk_enter(char *st);
char	*ft_gnl_strjoin(char *s1, char *s2);

#endif
