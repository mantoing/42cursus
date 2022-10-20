/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:06:30 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/20 16:01:41 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_top(t_stack *s, int data)
{
	t_link	*new;

	new = (t_link *)malloc(sizeof(t_link));
	if (new == NULL)
		prt_error(0);
	s->size += 1;
	if (s->head == NULL)
	{
		s->head = new;
		s->tail = new;
		new->item = data;
		new->next = NULL;
		new->prev = NULL;
		return (TRUE);
	}
	new->prev = s->tail;
	s->tail->next = new;
	s->tail = new;
	s->tail->next = NULL;
	new->item = data;
	return (TRUE);
}

int	pop_top(t_stack *s)
{
	int		ret;
	t_link	*cur;

	ret = 0;
	cur = NULL;
	ret = s->tail->item;
	cur = s->tail;
	if (s->size == 1)
	{
		free(cur);
		s->size--;
		s = NULL;
		return (ret);
	}
	s->tail = s->tail->prev;
	s->tail->next = NULL;
	s->size--;
	free(cur);
	return (ret);
}

void	prt_stack(t_stack *s)
{
	t_link	*cur;
	int		i;

	i = 0;
	cur = s->head;
	printf("<<<<<<<<<<%d\n", s->size);
	while (i++ < s->size)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
}

int	x(t_stack *stack, int prev_cnt)
{
	int		ret;
	t_link	*tmp;

	tmp = stack->tail;
	while (prev_cnt > 0)
	{
		tmp = tmp->prev;
		prev_cnt--;
	}
	ret = tmp->item;
	return (ret);
}
