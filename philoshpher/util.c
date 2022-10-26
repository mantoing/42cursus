/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:50:47 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/26 16:01:55 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "philo.h"

 long long	ft_get_time(void)
 {
	 struct timeval	time;
	 
	 gettimeofday(&time, NULL);
	 return (time.tv_sec * 1000 + time.tv_usec / 1000);
 }

 long long	ft_atoi(const char *str)
{
	int			i;
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res < 0)
			return ((sign + 1) / -2);
	}
	return ((long long)(res * sign));
}

void	ft_usleep(long long time)
{
	long long	start;

	start = ft_get_time();
	while (1)
	{
		if (ft_get_time() - start >= time)
			break ;
		usleep(100);	
	}
}