/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:44:16 by jaeywon           #+#    #+#             */
/*   Updated: 2022/08/26 19:49:53 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define ERROR -1
# define SUCCESS 0

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>

typedef	struct	s_info
{
	int	pid;
	int	flags;
}				t_info;

int		ft_putstr(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
size_t	ft_strlen(char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_pow(int num, int power);

#endif