/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:30:18 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/26 16:20:51 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_philo *philo;
	t_info info;
	
	printf("%d\n", ac);
	if (init_info(ac, av, &info) != 0)
		return (prt_error(1));
	philo = init_philo(&info);
	if (!philo)
		return (prt_error(2));
	if (init_mutex(&info, philo))
		return (prt_error(3));
		pthread_mutex_lock(&philo->info->print);
	//make_philo(&info, philo);
	return (0);
}