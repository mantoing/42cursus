/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:53:05 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/18 20:53:07 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_b_cnt(t_cnt *count)
{
    count->ra_cnt = 0;
    count->rb_cnt = 0;
    count->pa_cnt = 0;
}

void    only_pa(t_info *info, int size)
{
    while (size > 0)
    {
        pa(info);
        size--;
    }
}

void b_to_a(t_info *info, int size)
{
	t_cnt count;
    int tmp;

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
        return;
    }
    else if (size == 3)
    {
        sort_three(info, 1);
        return ;
    }
    init_b_cnt(&count);
    get_pivot(info, info->b, size);
    while (size > 0)
    {
        tmp = info->b->tail->item;
        if (tmp < info->pivot_small)
        {
            rb(info->b);
            count.rb_cnt++;
        }
        else
        {
            pa(info);
            count.pa_cnt++;
            tmp = info->a->tail->item;
            if (tmp < info->pivot_big)
            {
                ra(info->a);
                count.ra_cnt++;
            }
        }
        size--;
    }
	a_to_b(info, count.pa_cnt - count.ra_cnt);
    check_rrr(info, count.ra_cnt, count.rb_cnt);
	a_to_b(info, count.ra_cnt);
	b_to_a(info, count.rb_cnt);
}