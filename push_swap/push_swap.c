/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:06:43 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/18 23:08:32 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    first_put_arr(t_stack *stack, int ssize)
{
    int *arr;
    int i;
	t_link *cur;

	i = 0;
	arr = (int *)malloc(ssize * sizeof(int));
	if (!arr)
		prt_error(0);
	cur = stack->tail;
	while (i < ssize)
	{
		arr[i] = cur->item;
		cur = cur->prev;
		i++;
	}
	arr_qsort(arr, 0, --i);
	check_duplicate(arr, stack->size);
	free(arr);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_stack	a;
	t_stack	b;
	int		idx;

	idx = ac - 1;
	if (ac < 2)
		prt_error(ac);
	info.a = &a;
	info.b = &b;
	inint_headtail(&info);
	many_args(av, idx, &a);
	first_put_arr(info.a, info.a->size);
	if (!is_sorted(info.a, info.a->size, 0))
	{
		if (ac == 4)
			only_three_sort(info.a);
		else if (ac == 6)
			only_five_sort(&info);
		else
			a_to_b(&info, info.a->size);
	}
	return (0);
}
