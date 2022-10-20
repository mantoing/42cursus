/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:48:31 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/20 15:52:11 by jaeywon          ###   ########.fr       */
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
	if (x(info->a, 0) < x(info->a, 1) && x(info->a, 0) < x(info->a, 2))
	{
		pb(info);
		sort_two(info, 0);
		pa(info);
	}
	else if (x(info->a, 1) < x(info->a, 0) && x(info->a, 1) < x(info->a, 2))
	{
		ra(info->a);
		pb(info);
		rra(info->a);
		sort_two(info, 0);
		pa(info);
	}
	else if (x(info->a, 2) < x(info->a, 0) && x(info->a, 2) < x(info->a, 1))
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
	if (x(info->b, 0) > x(info->b, 1) && x(info->b, 0) > x(info->b, 2))
	{
		pa(info);
		sort_two(info, 1);
	}
	else if (x(info->b, 1) > x(info->b, 0) && x(info->b, 1) > x(info->b, 2))
	{
		rb(info->b);
		pa(info);
		rrb(info->b);
		sort_two(info, 1);
	}
	else if (x(info->b, 2) > x(info->b, 0) && x(info->b, 2) > x(info->b, 1))
	{
		rb(info->b);
		rb(info->b);
		pa(info);
		rrb(info->b);
		rrb(info->b);
		sort_two(info, 1);
	}
}

void	sort_two(t_info *info, int flag)
{
	t_link	*a_tmp;
	t_link	*b_tmp;

	a_tmp = info->a->tail;
	b_tmp = info->b->tail;
	if ((a_tmp->item > a_tmp->prev->item) && flag == 0)
		sa(info->a);
	if (flag == 1)
	{
		if (b_tmp->item < b_tmp->prev->item)
			sb(info->b);
		pa(info);
		pa(info);
	}
}
