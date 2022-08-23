/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:10:40 by jaeywon           #+#    #+#             */
/*   Updated: 2022/08/23 17:35:24 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(int pid, char byte)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (byte & (1 << i))
		{
			if (kill(pid, SIGUSR1) == SUCCESS)
				usleep(50);
			else
				ft_putstr("kill 1 Failed\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == SUCCESS)
				usleep(50);
			else
				ft_putstr("kill 2 Failed\n");
		}
		i--;
	}
}

void	send_msg(int pid, char *message)
{
	int	i;

	i = -1;
	while (message[++i])
		send_byte(pid, message[i]);
}

int	main(int ac, char **av)
{
	int		sv_pid;
	char	*message;
	int		i;

	if (ac != 3)
	{
		ft_putstr("AC ERROR\n");
		exit(0);
	}
	sv_pid = ft_atoi(av[1]);
	if (sv_pid <= 99 || sv_pid > 100000)
	{
		ft_putstr("PID ERROR\n");
		exit(0);
	}
	message = av[2];
	i = 0;
	send_msg(sv_pid, message);
	ft_putstr("message clear\n");
	return (0);
}
