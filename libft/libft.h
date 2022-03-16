/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonseoyun <wonseoyun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:45:30 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/16 18:03:33 by wonseoyun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void    ft_bzero(void *s, size_t n);
int     ft_isalnum(int c);
int     ft_isalpha(int c);
int	    ft_isascii(int c);
int	    ft_isdigit(int c);
int	    ft_isprint(int c);
char    *ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
size_t  ft_strlcpy(char *dest, const char *stc, size_t destsize);
int	    ft_strlen(char *str);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strrchr(const char *s, int c);
int     ft_tolower(int c);
int     ft_toupper(int c);
void    *ft_calloc(size_t count, size_t size);
char    *ft_strdup(const char *s1);
int     ft_atoi(const char *str);
void    *ft_memset(void *ptr, int b, size_t len);
void    *ft_memcpy(void *dest, const void *source, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t len);
void    ft_memchr(const void *ptr, int c, size_t len);

#endif