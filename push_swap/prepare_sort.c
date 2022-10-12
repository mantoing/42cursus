#include "push_swap.h"
#include <stdio.h>

void	arr_swap(int *arr, t_pivot *pv)
{
	if (pv->i > pv->j)
	{
		pv->tmp = arr[pv->j];
		arr[pv->j] = arr[pv->pivot];
		arr[pv->pivot] = pv->tmp;
	}
	else
	{
		pv->tmp = arr[pv->i];
		arr[pv->i] = arr[pv->j];
		arr[pv->j] = pv->tmp;
	}
}

void	init_pivot(t_pivot *pv, int start, int end)
{
	pv->pivot = start;
	pv->i = pv->pivot + 1;
	pv->j = end;
}

void	arr_qsort(int *arr, int start, int end)
{
	t_pivot pv;

	init_pivot(&pv, start, end);
	if (start >= end)
		return ;
	while (pv.i <= pv.j)
	{
		while (pv.i <= end && arr[pv.i] <= arr[pv.pivot])
			pv.i++;
		while (pv.j > start && arr[pv.j] >= arr[pv.pivot])
			pv.j--;
		arr_swap(arr, &pv);		
	}
	arr_qsort(arr, start, pv.j - 1);
	arr_qsort(arr, pv.j + 1, end);
}

void    get_pivot(t_info *info, t_stack *stack)
{
    int *arr;
    int i;
	t_link *cur;

    if (stack->size < 4)
        return ;
	i = 0;
	arr = (int *)malloc(stack->size * sizeof(int));
	if (!arr)
		prt_error();
	cur = stack->head;	
	while (i < stack->size)
	{
		arr[i] = cur->item;
		cur = cur->next;
		printf("%d", arr[i]);
		i++;
	}
	printf("\n");
	printf("%d\n", i);
	arr_qsort(arr, 0, --i);
	check_duplicate(arr, stack->size);
	info->pivot_small = arr[stack->size / 3];
	info->pivot_big = arr[2 * stack->size / 3];
	// free(arr);
	i = 0;
	while (i < stack->size)
	{
		printf("%d", arr[i]);
		i++;
	}
	printf("\n");
	printf("%d\n", info->pivot_small);
	printf("%d\n", info->pivot_big);
}