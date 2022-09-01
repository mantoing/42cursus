/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:33:55 by jaeywon           #+#    #+#             */
/*   Updated: 2022/09/01 18:04:31 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_flag;

static void	handler(int signal, siginfo_t *siginfo, void *p)
{
	(void)signal;
	(void)p;
	g_flag = siginfo->si_pid;
}

void	kill_sigusr(int bit_tmp, int kill_flag, int pid)
{
	if (bit_tmp == 1)
		kill_flag = kill(pid, SIGUSR1);
	else if (bit_tmp == 0)
		kill_flag = kill(pid, SIGUSR2);
	if (kill_flag == -1)
		exit(1);
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
				kill_sigusr(bit_tmp, kill_flag, pid);
				bit_cnt++;
			}
		}
		message++;
	}
	ft_putstr("message clear\n");
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
	return (0);
}
