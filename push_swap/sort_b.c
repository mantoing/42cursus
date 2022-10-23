/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:53:05 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/20 20:13:41 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only_pa(t_info *info, int size)
{
	while (size > 0)
	{
		pa(info);
		size--;
	}
}

void	split_bnum(t_info *info, t_cnt *count)
{
	int	tmp;

	tmp = info->b->tail->item;
	if (tmp < info->pivot_small)
	{
		rb(info->b);
		count->rb_cnt++;
	}
	else
	{
		pa(info);
		count->pa_cnt++;
		tmp = info->a->tail->item;
		if (tmp < info->pivot_big)
		{
			ra(info->a);
			count->ra_cnt++;
		}
	}
}

void	b_to_a(t_info *info, int size)
{
	t_cnt	count;
	int		tmp;

	init_b_cnt(&count);
	get_pivot(info, info->b, size);
	while (size > 0)
	{
		split_bnum(info, &count);
		size--;
	}
	do_a_to_b(info, count.pa_cnt - count.ra_cnt);
	check_rrr(info, count.ra_cnt, count.rb_cnt);
	do_a_to_b(info, count.ra_cnt);
	do_b_to_a(info, count.rb_cnt);
}

void	do_b_to_a(t_info *info, int size)
{
	if (is_sorted(info->b, size, 1))
	{
		only_pa(info, size);
		return ;
	}
	if (size == 1)
	{
		pa(info);
		return ;
	}
	else if (size == 2)
	{
		sort_two(info, 1);
		return ;
	}
	else if (size == 3)
	{
		sort_three(info, 1);
		return ;
	}
	b_to_a(info, size);
}
