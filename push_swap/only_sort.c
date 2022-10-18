#include "push_swap.h"

void    only_three_sort(t_stack *stack)
{
    int a;
    int b;
    int c;

    a = stack->tail->item;
    b = stack->tail->prev->item;
    c = stack->head->item;
    // printf("a = %d\n b = %d\n c = %d\n", a, b, c);
    if (a > b && b > c)
    {
        sa(stack);
        rra(stack);
    }
    else if (a > b && b < c && a > c) 
        ra(stack);
    else if (a < b && b > c && a > c)
        rra(stack);
    else if (a > b && b < c && a < c)
        sa(stack);
    else if (a < b && b > c && a < c)
    {
        ra(stack);
        sa(stack);
        rra(stack);
    }
    else
        return ;
}

void    only_five_sort(t_info *info)
{
    int *arr;
    int i;
	t_link *cur;
    int center;

    i = 0;
	arr = (int *)malloc(5 * sizeof(int));
	if (!arr)
		prt_error(0);
	cur = info->a->tail;
	while (i < 5)
	{
		arr[i] = cur->item;
		cur = cur->prev;
		i++;
	}
	arr_qsort(arr, 0, --i);
    center = arr[2];
    i = 0;
    while (i < 5)
    {
        if (info->a->tail->item < arr[2])
            pb(info);
        else
            ra(info->a);
        i++;
    }
    only_three_sort(info->a);
    sort_two(info, 1);
    free(arr);
}