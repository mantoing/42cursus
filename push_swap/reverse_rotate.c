/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:06:51 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/18 20:34:23 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cal_rr(t_stack *stack)
{
	t_link	*tmp;

	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail->next = tmp;
	tmp->prev = stack->tail;
	stack->tail = tmp;
}

void	rra(t_stack *stack)
{
	if (stack->size == 2)
		sa(stack);
	else if (stack->size > 2)
	{
		cal_rr(stack);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *stack)
{
	if (stack->size == 2)
		sb(stack);
	else if (stack->size > 2)
	{
		cal_rr(stack);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
		cal_rr(stack_a);
		cal_rr(stack_b);
		write(1, "rrr\n", 4);
}
