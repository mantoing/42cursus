#include "minitalk.h"

int main(int ac, char **av)
{
	int	pid;

	pid = getpid();
	if (ac == 1)
	{
		ft_putstr("PID:   ");
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}