/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:27:17 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/23 20:51:13 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_info
{
	int	philo_num;
	int	time_d;
	int	time_e;
	int	time_s;
	int	start_time;
	int	eatingnum;
}	t_info;


void	prt_error();
int	init_info(int ac, char **av, t_info *info);
long long	ft_atoi(const char *str);

#endif