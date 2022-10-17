/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:48:31 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/17 20:10:13 by jaeywon          ###   ########.fr       */
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
		check_r(info, 0);
		pb(info);
		check_rr(info, 0);
		sort_two(info, 0);
		pa(info);
	}
	else if (c < a && c < b)
	{
		check_r(info, 0);
		check_r(info, 0);
		pb(info);
		check_rr(info, 0);
		check_rr(info, 0);
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
	if (a > b && a > c)
	{
		pa(info);
		sort_two(info, 1);
	}
	else if (b > a && b > c)
	{
		check_r(info, 1);
		pa(info);
		check_rr(info, 1);
		sort_two(info, 1);
	}
	else if (c > a && c > b)
	{
		check_r(info, 1);
		check_r(info, 1);
		pa(info);
		check_rr(info, 1);
		check_rr(info, 1);
		sort_two(info, 1);
	}
}

void	sort_two(t_info *info, int flag)
{
	t_link *a_tmp;
	t_link *b_tmp;

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