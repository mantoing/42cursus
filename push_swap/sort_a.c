/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:52:58 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/18 21:16:45 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    check_rrr(t_info *info, int ra_cnt, int rb_cnt)
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

void    init_a_cnt(t_cnt *count)
{
    count->ra_cnt = 0;
    count->rb_cnt = 0;
    count->pb_cnt = 0;
}

int is_sorted(t_stack *stack, int size, int flag)
{
    t_link *tmp;

    if (size < 2)
        return (TRUE);
    tmp = stack->tail;    
    if (flag == 0)
    {
        while (size > 1)
        {
            if (tmp->item > tmp->prev->item)
                return (FALSE);
            tmp = tmp->prev;
            size--;
        }
    }
    else
    {
        while (size > 1)
        {
            if (tmp->item < tmp->prev->item)
                return (FALSE);
            tmp = tmp->prev;
            size--;
        }
    }
    return (TRUE);
}

void    a_to_b(t_info *info, int size)
{
    t_cnt   count;
    int tmp;
    
    
    if (is_sorted(info->a, size, 0))
    {
        return ;
    }
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
    init_a_cnt(&count);
    get_pivot(info, info->a, size);
    while (size > 0)
    {
        tmp = info->a->tail->item;
        if (tmp >= info->pivot_big)
        {
            ra(info->a);
            count.ra_cnt++;
        }
        else
        {
            pb(info);
            count.pb_cnt++;
            tmp = info->b->tail->item;
            if (tmp >= info->pivot_small)
            {
                rb(info->b);
                count.rb_cnt++;
            }
        }
        size--;        
    }
   
    check_rrr(info, count.ra_cnt, count.rb_cnt);
    // prt_stack(info->a);
    // prt_stack(info->b);
    // printf("\n---------------\n");
    a_to_b(info, count.ra_cnt);
    b_to_a(info, count.rb_cnt);
    b_to_a(info, count.pb_cnt - count.rb_cnt);
}