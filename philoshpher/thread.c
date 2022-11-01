/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:57:00 by jaeywon           #+#    #+#             */
/*   Updated: 2022/11/01 18:18:09 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread(t_philo *philo)
{
	if ((philo->pos % 2))
		ft_usleep(philo->info->time_e / 2);
	while(1)
	{
		pthread_mutex_lock(&philo->info->print);
		if (philo->end_flag || philo->info->finished)
			break;
		pthread_mutex_unlock(&philo->info->print);
		action_philo(philo);
	}
	pthread_mutex_unlock(&philo->info->print);
	return (0);
}

int	check_all_eat(t_philo *philo, t_info info)
{
	int i;

	i = -1;
	while (++i < info.philo_num)
	{
		pthread_mutex_lock(&philo->info->print);
		if (!philo[i].end_flag)
		{
			pthread_mutex_unlock(&philo->info->print);
			return (0);
		}
		pthread_mutex_unlock(&philo->info->print);
	}
	return (1);
}

int	check_philo_die(t_info *info, t_philo *philo)
{
	int	i;
	long long now;

	while (!check_all_eat(philo, *info))
	{
		i = -1;
		while (++i < info->philo_num)
		{
			pthread_mutex_lock(&philo->info->print);
			now = ft_get_time();
			if ((now - philo[i].last_eat) >= info->time_d)
			{
				printf("%lld %d died\n", now - philo->info->start_time, philo[i].pos + 1);
				info->finished = 1;
				pthread_mutex_unlock(&philo->info->print);
				return (1);
			}
			pthread_mutex_unlock(&philo->info->print);
		}
		usleep(2500);
	}
	return (0);
}

int	solo_philo(t_info *info, t_philo *phil)
{
	if (info->philo_num == 1)
	{
		pthread_mutex_lock(phil->l_fork);
		prt_philo(phil->pos, phil, "has taken a fork");
		ft_usleep(info->time_d);
		prt_philo(phil[0].pos, phil, "died");
		return (1);
	}
	return (0);
}

int make_philo(t_info *info, t_philo *philo)
{
	int	i;

	if (solo_philo(info, philo))
		return (0);
	i = -1;
	while (++i < info->philo_num)
	{	
		philo[i].last_eat = ft_get_time();
		if (pthread_create(&(philo[i].p_thread), NULL, (void *)ft_thread, &(philo[i])))
			return (1);
	}
	check_philo_die(info, philo);
	repeat_join(philo, *info);
	return (0);
}