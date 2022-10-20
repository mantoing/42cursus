/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:06:26 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/20 16:00:20 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cal_r(t_stack *stack)
{
	t_link	*tmp;

	tmp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	stack->head->prev = tmp;
	tmp->next = stack->head;
	stack->head = tmp;
}

void	ra(t_stack *stack)
{
	t_link	*tmp;

	if (stack->size == 2)
		sa(stack);
	else if (stack->size > 2)
	{
		cal_r(stack);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack *stack)
{
	t_link	*tmp;

	if (stack->size == 2)
		sb(stack);
	else if (stack->size > 2)
	{
		cal_r(stack);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	cal_r(stack_a);
	cal_r(stack_b);
	write(1, "rr\n", 3);
}
