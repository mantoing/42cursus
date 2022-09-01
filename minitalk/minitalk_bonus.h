/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:35:17 by jaeywon           #+#    #+#             */
/*   Updated: 2022/09/01 16:37:38 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define ERROR -1
# define SUCCESS 0

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_info
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