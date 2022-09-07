#include "push_swap.h"

void	init_stack(int ac, char **av, t_info *stack)
{
	int tmp;

	tmp = ft_atoi(av[--ac]);
	stack->header = NULL;
	stack->tailer = NULL;
	while (ac > 1)
	{	
		tmp = ft_atoi(av[--ac]);
		push_top(stack->a, tmp);
	}
	stack->b = NULL;
}

int main(int ac, char **av)
{
	t_info	info;

	if (ac < 2)
		prt_error();
	init_stack(ac, av, &info);
	return (0);
}