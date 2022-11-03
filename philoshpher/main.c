/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:30:18 by jaeywon           #+#    #+#             */
/*   Updated: 2022/11/03 16:58:27 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_all(t_philo *philo, t_info info)
{
	int	i;

	i = -1;
	while (++i < info.philo_num)
		pthread_mutex_destroy(&info.fork[i]);
	pthread_mutex_destroy(&philo->info->print);
	free(philo);
	free(info.fork);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_info	info;

	if (init_info(ac, av, &info) != 0)
		return (prt_error(1));
	philo = init_philo(&info);
	if (!philo)
		return (prt_error(2));
	if (init_mutex(&info, philo) != 0)
		return (prt_error(3));
	if (make_philo(&info, philo) != 0)
		return (prt_error(4));
	destroy_all(philo, info);
	return (0);
}
