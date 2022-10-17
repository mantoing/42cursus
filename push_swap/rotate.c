/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:06:26 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/17 20:04:36 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_r(t_info *info, int flag)
{
	if (flag == 0)
	{
		ra(info->a);
		write(1, "ra\n", 3);
	}
	else if (flag == 1)
	{
		rb(info->b);
		write(1, "rb\n", 3);
	}
	else
	{
		rr(info);
		write(1, "rr\n", 3);
	}
}

void	ra(t_stack *stack_a)
{
	t_link	*tmp;

	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size > 2)
	{
		tmp = stack_a->tail;
		stack_a->tail = stack_a->tail->prev;
		stack_a->tail->next = NULL;
		stack_a->head->prev = tmp;
		tmp->next = stack_a->head;
		stack_a->head = tmp;
	}
}

void	rb(t_stack *stack_b)
{
	t_link	*tmp;

	if (stack_b->size == 2)
		sb(stack_b);
	else if (stack_b->size > 2)
	{
		tmp = stack_b->tail;
		stack_b->tail = stack_b->tail->prev;
		stack_b->tail->next = NULL;
		stack_b->head->prev = tmp;
		tmp->next = stack_b->head;
		stack_b->head = tmp;
	}
}

void	rr(t_info *stack)
{
	ra(stack->a);
	rb(stack->b);
}
