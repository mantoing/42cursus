/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:06:43 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/17 20:41:45 by jaeywon          ###   ########.fr       */
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
	a_to_b(&info, info.a->size);
	// prt_stack(&a);
	// prt_stack(&b);
	return (0);
}
