/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:50:17 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/27 21:57:52 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(int ac, char **av, t_info *info)
{
	if ((ac != 5 && ac != 6) || ac < 2)
		return (1);
	info->philo_num = ft_atoi(av[1]);
	info->time_d = ft_atoi(av[2]);
	info->time_e = ft_atoi(av[3]);
	info->time_s = ft_atoi(av[4]);
	info->finished = 0;
	if (!info->philo_num || !info->time_d || !info->time_e || !info->time_s)
		return (1);
	if (ac == 6)
	{
		info->eatingnum = ft_atoi(av[5]);
		if (!info->eatingnum)
			return (1);
	}
	return (0);
}

int	init_mutex(t_info *info, t_philo *phil)
{
	int i;

	if (pthread_mutex_init(&(info->print), NULL))
		return (1);
	i = -1;
	info->fork = malloc(info->philo_num * sizeof(pthread_mutex_t));
	if (!(info->fork))
		return (1);
	while (++i < info->philo_num)
	{
		if(pthread_mutex_init(&(info->fork[i]), NULL))
			return (1);
	}
	i = -1;
	while (++i < info->philo_num)
	{
		phil[i].l_fork = &info->fork[i];
		phil[i].r_fork = &info->fork[(i + 1) % info->philo_num];
	}
	return (0);
}

t_philo	*init_philo(t_info *info)
{
	t_philo *phil;
	int		i;

	i = -1;
	phil = malloc(info->philo_num * sizeof(t_philo));
	if (!phil)
		return (NULL);
	while (++i < info->philo_num)
	{
		phil[i].info = info;
		phil[i].end_flag = 0;
		phil[i].pos = i;
		phil[i].start_time = ft_get_time();
		phil[i].last_eat = 0;
		phil[i].eat_cnt = 0;
	}
	return (phil);
}