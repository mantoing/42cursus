/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:27:17 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/24 21:32:39 by jaeywon          ###   ########.fr       */
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
	pthread_mutex_t	*fork;
}	t_info;

typedef struct s_philo
{
	pthread_t	p_thread;
	t_info		*info;
	int			pos;
	long long	last_eat;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
}	t_philo;


int	prt_error(int code);
int	init_info(int ac, char **av, t_info *info);
long long	ft_atoi(const char *str);
long long	ft_get_time(void);
t_philo	*make_philo(t_info *info);
int	init_mutex(t_info *info, t_philo *phil);

#endif