#include "push_swap.h"

void    check_rrr(t_info *info, int ra_cnt, int rb_cnt)
{
    while (ra_cnt-- > 0 && rb_cnt-- > 0)
        rrr(info);
    while (ra_cnt-- > 0)
        rra(info->a);
    while (rb_cnt-- > 0)
        rrb(info->b);
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
        while (tmp->prev != 0)
        {
            if (tmp->item < tmp->prev->item)
                return (FALSE);
            tmp = tmp->prev;
        }
    }
    else
    {
        while (tmp->prev != 0)
        {
            if (tmp->item < tmp->prev->item)
                return (FALSE);
            tmp = tmp->prev;
        }
    }
    return (TRUE);
}

void    a_to_b(t_info *info, int size)
{
    t_cnt   count;
    int tmp;
    
    init_a_cnt(&count);
    // printf("ra : %d\n rb : %d\n pb - rb  %d\n", count.ra_cnt, count.rb_cnt, count.pb_cnt - count.rb_cnt);
    get_pivot(info, info->a); 
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
    while (size > 0)
    {
        tmp = info->a->tail->item;
        if (tmp >= info->pivot_big)
        {
            ra(info->a);
            count.ra_cnt++;
        }
        else
            pb(info);
            count.pb_cnt++;
            if (tmp >= info->pivot_small)
            {
                rb(info->b);
                count.rb_cnt++;
            }
        size--;        
    }
    prt_stack(info->a);
    prt_stack(info->b);
    check_rrr(info, count.ra_cnt, count.rb_cnt);
    printf("ra : %d\n rb : %d\n pb - rb  %d\n", count.ra_cnt, count.rb_cnt, count.pb_cnt - count.rb_cnt);
    a_to_b(info, count.ra_cnt);
    printf("[%d]\n", count.rb_cnt);
    b_to_a(info, count.rb_cnt);
    b_to_a(info, count.pb_cnt - count.rb_cnt);
}