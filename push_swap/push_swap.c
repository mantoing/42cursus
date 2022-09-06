#include "push_swap.h"

void	print_error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

void init_stack_a(int ac, char **av, t_stack *a)
{
	int i;

	i = ac;
	while (--i > 0)
	{
		a->data = av[i]; //stack make
		a = a->next;	
	}

}

int	main(int ac, char **av)
{
	int	i;
	t_stack a;
	t_stack b;
	
	if (ac < 2)
	{
		print_error("AC ERROR\n");
		exit(1);
	}
	init_stack_a()




}