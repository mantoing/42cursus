/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:30:18 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/24 21:34:01 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_philo *philo;
	t_info info;
	
	if (!init_info(ac, av, &info))
		return (prt_error(1));
	philo = make_philo(&info);
	if (!philo)
		return (prt_error(2));
	if (init_mutex(&info, philo))
		return (prt_error(3));
}