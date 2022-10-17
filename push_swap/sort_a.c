#include "push_swap.h"

void    check_rrr(t_info *info, int ra_cnt, int rb_cnt)
{
    while (ra_cnt > 0 && rb_cnt > 0)
    {
        check_rr(info, 2);
        ra_cnt--;
        rb_cnt--;
    }
    while (ra_cnt > 0)
    {
        check_rr(info, 0);
        ra_cnt--;
    }
    while (rb_cnt > 0)
    {
        check_rr(info, 1);
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
    get_pivot(info, info->a);
    while (size > 0)
    {
        tmp = info->a->tail->item;
        if (tmp >= info->pivot_big)
        {
            check_r(info, 0);
            count.ra_cnt++;
        }
        else
        {
            pb(info);
            count.pb_cnt++;
            tmp = info->b->tail->item;
            if (tmp >= info->pivot_small)
            {
                check_r(info, 1);
                count.rb_cnt++;
            }
        }
        size--;        
    }
    check_rrr(info, count.ra_cnt, count.rb_cnt);
     prt_stack(info->a);
    prt_stack(info->b);
    printf("------%d, %d\n", count.pb_cnt, count.rb_cnt);
    printf("^^^^^^^^%d, %d\n", info->pivot_big, info->pivot_small);
    a_to_b(info, count.ra_cnt);
    b_to_a(info, count.rb_cnt);
    prt_stack(info->a);
    prt_stack(info->b);
    printf("------%d, %d\n", count.pb_cnt, count.rb_cnt);
    printf("^^^^^^^^%d, %d\n", info->pivot_big, info->pivot_small);
    sleep(1);
    b_to_a(info, count.pb_cnt - count.rb_cnt);
    prt_stack(info->a);
    prt_stack(info->b);
}