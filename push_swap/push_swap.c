/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:06:43 by jaeywon           #+#    #+#             */
/*   Updated: 2022/09/23 18:30:19 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*put_stack_in_arr(t_link *list, int size)
{
	int *arr;
	int	i;

	arr = (int *)malloc(sizeof(int));
	while (i < size)
	{
		arr[i] = list->next
	}
}

int	main(int ac, char **av)
{
	t_info	info;
	t_stack	a;
	t_stack	b;
	int		idx;

	idx = ac - 1;
	if (ac < 2)
		prt_error();
	info.a = &a;
	info.b = &b;
	inint_headtail(&info);
	many_args(av, idx, &a);
	prt_stack(&a);
	// sa(&a);
	// pb(&info);
	// pb(&info);
	// pb(&info);
	// pb(&info);
	// ra(&a);
	// ra(&b);
	// prt_stack(&a);
	// prt_stack(&b);
	// rra(&a);
	// rrb(&b);
	// prt_stack(&a);
	// prt_stack(&b);
	return (0);
}
