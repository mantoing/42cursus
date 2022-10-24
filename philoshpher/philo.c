/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:14:02 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/24 21:05:39 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*make_philo(t_info *info)
{
	t_philo *phil;
	int		i;

	i = 0;
	phil = malloc(info->philo_num * sizeof(t_philo));
	if (!phil)
		return (NULL);
	while (++i < info->philo_num)
	{
		phil[i].info = info;
		phil[i].pos = i;
	}
	return (phil);
}