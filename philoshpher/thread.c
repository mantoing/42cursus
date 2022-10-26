/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:57:00 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/26 16:13:00 by jaeywon          ###   ########.fr       */
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
	return (0);
}

int make_philo(t_info *info, t_philo *philo)
{
	int	i;

// 	if (혼자일 경우)
// 		return (0);
	i = 0;
	while (i++ < info->philo_num)
	{
		philo[i].last_eat = ft_get_time();
		if (pthread_create(&(philo[i].p_thread), NULL, (void *)ft_thread, &(philo[i])))
			return (1);
	}
	return (0);
}