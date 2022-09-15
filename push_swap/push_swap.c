#include "push_swap.h"

int main(int ac, char **av)
{
	t_info	info;
	t_stack	a;
	t_stack b;
	int	idx;

	idx = ac - 1;
	if (ac < 2)
		prt_error();
	info.a = &a;
	info.b = &b;
	inint_headtail(&info);
	many_args(av, idx, &a);
	prt_stack(&a);
	sa(&a);
	pb(&info);
	pb(&info);
	pb(&info);
	pb(&info);
	ra(&a);
	ra(&b);
	prt_stack(&a);
	prt_stack(&b);
	rra(&a);
	rrb(&b);
	prt_stack(&a);
	prt_stack(&b);
	return (0);
}