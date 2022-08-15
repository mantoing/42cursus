#include "minitalk.h"

void send_byte(char byte, int pid)
{
	int i;

	
}

void	send_msg(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i++])
		send_byte(str[i], pid);

}

int main(int ac, char **av)
{
	int sv_pid;
	char *message;

	if (av != 3)
	{
		ft_putstr("AC ERROR\n");
		exit(0);
	}
	sv_pid = ft_atoi(av[1]);
	message = av[2];
	return (0);
}