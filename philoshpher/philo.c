/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:14:02 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/26 15:58:43 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	prt_phillo(int pos, t_philo *phil, char *str)
{
	long long	time;

	time = ft_get_time();
	pthread_mutex_lock(&(phil->info->print));
	if (!phil->end_flag || !phil->info->finished)
		printf("%lld %d %s \n", time - phil->info->start_time, pos + 1, str);
	pthread_mutex_unlock(&phil->info->print);
	return (0);
}

void	sleeping(t_philo *philo)
{
	prt_phillo(philo->pos, philo, "is sleeping");
	ft_usleep(philo->info->time_s);
}

void	action_philo(t_philo *philo)
{
	// eating(philo);
	sleeping(philo);
	prt_phillo(philo->pos, philo, "is thinking");
}