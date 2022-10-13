/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:06:43 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/13 19:49:51 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	a_to_b(&info, info.a->size);
	// sa(&a);
	// printf("head : %d\n", info.a->head->item);
	// pb(&info);
	// pb(&info);
	// pb(&info);
	// pb(&info);ß
	// ra(&a);
	// ra(&b);
	prt_stack(&a);
	prt_stack(&b);
	// rra(&a);
	// rrb(&b);
	// prt_stack(&a);
	// prt_stack(&b);
	return (0);
}
