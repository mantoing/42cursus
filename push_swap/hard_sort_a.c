#include "push_swap.h"

void	test(t_info *info, int size)
{
	int a;
	int b;
	int c;

	a = info->a->tail->item;
	b = info->a->tail->prev->item;
	c = info->a->tail->prev->prev->item;
	if (a < b && a < c)
	{
		pb(info->a);
		sort_two(info, 0);
		pa(info->a);
	}
	else if (b < a && b < c)
	{

	}
	else if (c < a && c < b)
	{
		
	}
}

void	sort_two(t_info *info, int flag)
{
	t_link *a_tmp;
	t_link *b_tmp;

	a_tmp = info->a->tail;
	b_tmp = info->b->tail;
	if ((a_tmp->item < a_tmp->prev->item) && flag == 0)
	{
		printf("head = %d\n", a_tmp->item);
		sa(info->a);
		printf("test2\n");
	}
	if (flag == 1)
	{
		if (b_tmp->item > b_tmp->prev->item)
			sb(info->b);
		pa(info);
		pa(info);	
	}
}