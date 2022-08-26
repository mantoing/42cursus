/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:10:40 by jaeywon           #+#    #+#             */
/*   Updated: 2022/08/26 21:45:59 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_flag;

static void	handler(int signal, siginfo_t *siginfo, void *p)
{
	void	*tmp;
	int		sig_del;

	sig_del = signal;
	tmp = p;
	g_flag = siginfo->si_pid;
}

void	send_byte(int pid, char *message)
{
	int	bit_cnt;
	int	kill_flag;
	int	bit_tmp;

	kill_flag = 0;
	bit_cnt = 0;
	while (*message)
	{
		bit_cnt = 0;
		while (bit_cnt < 8)
		{
			if (g_flag)
			{
				g_flag = 0;
				bit_tmp = *message >> (7 - bit_cnt) & 1;
				if (bit_tmp == 1)
					kill_flag = kill(pid, SIGUSR1);
				else if (bit_tmp == 0)
					kill_flag = kill(pid, SIGUSR2);
				if (kill_flag == -1)
					exit(1);
				bit_cnt++;
			}
		}
		message++;
	}
}

void	send_msg(int pid, char *message)
{
	int					i;
	struct sigaction	siga;

	i = 0;
	siga.sa_sigaction = &handler;
	siga.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &siga, NULL);
	send_byte(pid, message);
	exit(0);
}

int	main(int ac, char **av)
{
	int		sv_pid;
	char	*message;

	g_flag = 1;
	if (ac != 3)
	{
		ft_putstr("AC ERROR\n");
		exit(1);
	}
	sv_pid = ft_atoi(av[1]);
	if (sv_pid <= 99 || sv_pid > 100000)
	{
		ft_putstr("PID ERROR\n");
		exit(0);
	}
	message = av[2];
	send_msg(sv_pid, message);
	ft_putstr("message clear\n");
	return (0);
}
