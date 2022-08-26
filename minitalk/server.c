/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:44:37 by jaeywon           #+#    #+#             */
/*   Updated: 2022/08/26 21:36:01 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

void	prt_pid(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("PID:   ");
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

void	convert_bin_char(int *arr)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < 8)
	{
		if (arr[i] == 1)
			res += ft_pow(2, (7 - i));
		i++;
	}
	write(1, &res, 1);
}

static void	handler(int signal, siginfo_t *siginfo, void *p)
{
	static int	arr[8];
	static int	i = 0;

	(void)p;
	g_info.pid = siginfo->si_pid;
	if (signal == SIGUSR1)
		arr[i] = 1;
	else if (signal == SIGUSR2)
		arr[i] = 0;
	i++;
	if (i == 8)
	{
		convert_bin_char(arr);
		i = 0;
	}
	g_info.flags = 1;
}

int	main(int ac, char **av)
{
	struct sigaction	siga;

	(void)av;
	siga.sa_sigaction = &handler;
	siga.sa_flags = SA_SIGINFO;
	prt_pid();
	if (ac != 1)
	{
		ft_putstr("AC ERROR\n");
		exit(1);
	}
	if (sigaction(SIGUSR1, &siga, NULL) == ERROR)
		ft_putstr("signal reception failure\n");
	if (sigaction(SIGUSR2, &siga, NULL) == ERROR)
		ft_putstr("signal reception failure\n");
	while (1)
	{
		if (g_info.flags)
		{
			g_info.flags = 0;
			kill(g_info.pid, SIGUSR1);
		}
	}
	return (0);
}
