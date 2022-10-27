/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:27:17 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/27 21:57:40 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_info
{
	int	philo_num;
	int	time_d;
	int	time_e;
	int	time_s;
	int	eatingnum;
	int finished;
	pthread_mutex_t	*fork;
	pthread_mutex_t print;
}	t_info;

typedef struct s_philo
{
	pthread_t	p_thread;
	t_info		*info;
	int			eat_cnt;
	int			pos;
	long long	last_eat;
	int			end_flag;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	int	start_time;
}	t_philo;


int	prt_error(int code);
int	init_info(int ac, char **av, t_info *info);
long long	ft_atoi(const char *str);
long long	ft_get_time(void);
t_philo	*init_philo(t_info *info);
int	init_mutex(t_info *info, t_philo *phil);
void	action_philo(t_philo *philo);
void	sleeping(t_philo *philo);
void	prt_philo(int pos, t_philo *phil, char *str);
void	ft_usleep(long long time);
int make_philo(t_info *info, t_philo *philo);
void	*ft_thread(t_philo *philo);

#endif