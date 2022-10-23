/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:50:17 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/23 20:58:12 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(int ac, char **av, t_info *info)
{
	if (ac != 5 && ac != 6)
		return (1);	
	info->philo_num = ft_atoi(av[1]);
	info->time_d = ft_atoi(av[2]);
	info->time_e = ft_atoi(av[3]);
	info->time_s = ft_atoi(av[4]);
	info->start_time = ft_get_time();
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