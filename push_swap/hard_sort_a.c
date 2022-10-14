/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:48:31 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/14 18:19:24 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_info *info, int flag)
{
	if (flag == 0)
		a_three_sort(info);
	else
		b_three_sort(info);	
}

void	a_three_sort(t_info *info)
{
	int a;
	int b;
	int c;

	a = info->a->tail->item;
	b = info->a->tail->prev->item;
	c = info->a->tail->prev->prev->item;
	if (a < b && a < c)
	{
		pb(info);
		sort_two(info, 0);
		pa(info);
	}
	else if (b < a && b < c)
	{
		ra(info->a);
		pb(info);
		rra(info->a);
		sort_two(info, 0);
		pa(info);
	}
	else if (c < a && c < b)
	{
		ra(info->a);
		ra(info->a);
		pb(info);
		rra(info->a);
		rra(info->a);
		sort_two(info, 0);
		pa(info);
	}
}

void	b_three_sort(t_info *info)
{
	int a;
	int b;
	int c;

	a = info->b->tail->item;
	b = info->b->tail->prev->item;
	c = info->b->tail->prev->prev->item;
	if (a < b && a < c)
	{
		pa(info);
		sort_two(info, 1);
		pb(info);
	}
	else if (b < a && b < c)
	{
		rb(info->b);
		pa(info);
		rrb(info->b);
		sort_two(info, 1);
		pb(info);
	}
	else if (c < a && c < b)
	{
		rb(info->b);
		rb(info->b);
		pa(info);
		rrb(info->b);
		rrb(info->b);
		sort_two(info, 1);
		pb(info);
	}
}

void	sort_two(t_info *info, int flag)
{
	t_link *a_tmp;
	t_link *b_tmp;

	a_tmp = info->a->tail;
	b_tmp = info->b->tail;
	if ((a_tmp->item < a_tmp->prev->item) && flag == 0)
		sa(info->a);
	if (flag == 1)
	{
		if (b_tmp->item > b_tmp->prev->item)
			sb(info->b);
		pa(info);
		pa(info);	
	}
}