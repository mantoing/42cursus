/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:52:58 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/20 16:44:44 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rrr(t_info *info, int ra_cnt, int rb_cnt)
{
	while (ra_cnt > 0 && rb_cnt > 0)
	{
		rrr(info->a, info->b);
		ra_cnt--;
		rb_cnt--;
	}
	while (ra_cnt > 0)
	{
		rra(info->a);
		ra_cnt--;
	}
	while (rb_cnt > 0)
	{
		rrb(info->b);
		rb_cnt--;
	}
}

void	split_anum(t_info *info, t_cnt *count)
{
	int	tmp;

	tmp = info->a->tail->item;
	if (tmp >= info->pivot_big)
	{
		ra(info->a);
		count->ra_cnt++;
	}
	else
	{
		pb(info);
		count->pb_cnt++;
		tmp = info->b->tail->item;
		if (tmp >= info->pivot_small)
		{
			rb(info->b);
			count->rb_cnt++;
		}
	}
}

void	zerosplit_anum(t_info *info, t_cnt *count)
{
	int	tmp;

	tmp = info->a->tail->item;
	if (tmp >= info->pivot_big)
	{
		ra(info->a);
		count->ra_cnt++;
	}
	else
	{
		pb(info);
		count->pb_cnt++;
		tmp = info->b->tail->item;
		if (tmp < info->pivot_small)
		{
			rb(info->b);
			count->rb_cnt++;
		}
	}
}

void	a_to_b(t_info *info, int size)
{
	t_cnt	count;
	int		tmp;

	init_a_cnt(&count);
	get_pivot(info, info->a, size);
	while (size > 0)
	{
		if (info->num == 0)
			zerosplit_anum(info, &count);
		else
			split_anum(info, &count);
		size--;
	}
	if (info->num != 0)
		check_rrr(info, count.ra_cnt, count.rb_cnt);
	info->num++;
	do_a_to_b(info, count.ra_cnt);
	do_b_to_a(info, count.rb_cnt);
	do_b_to_a(info, count.pb_cnt - count.rb_cnt);
}

void	do_a_to_b(t_info *info, int size)
{
	if (is_sorted(info->a, size, 0))
		return ;
	if (size == 2)
	{
		sort_two(info, 0);
		return ;
	}
	else if (size == 3)
	{
		sort_three(info, 0);
		return ;
	}
	a_to_b(info, size);
}
