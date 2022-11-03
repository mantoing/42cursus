/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:14:02 by jaeywon           #+#    #+#             */
/*   Updated: 2022/11/03 19:29:35 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prt_philo(int pos, t_philo *phil, char *str)
{
	long long	time;
	long long	pass;

	time = ft_get_time();
	pass = ft_get_passed_time(phil->info->start_time);
	pthread_mutex_lock(&(phil->info->print));
	if (!phil->end_flag && !phil->info->finished)
		printf("%lld %d %s\n", pass, pos + 1, str);
	pthread_mutex_unlock(&phil->info->print);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	prt_philo(philo->pos, philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	prt_philo(philo->pos, philo, "has taken a fork");
	prt_philo(philo->pos, philo, "is eating");
	philo->eat_cnt++;
	ft_usleep(philo->info->time_e);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_lock(&philo->info->print);
	philo->last_eat = ft_get_time();
	if (philo->info->eatingnum == philo->eat_cnt)
		philo->end_flag = 1;
	pthread_mutex_unlock(&philo->info->print);
}

void	sleeping(t_philo *philo)
{
	prt_philo(philo->pos, philo, "is sleeping");
	ft_usleep(philo->info->time_s);
}

void	action_philo(t_philo *philo)
{
	eating(philo);
	sleeping(philo);
	prt_philo(philo->pos, philo, "is thinking");
}
