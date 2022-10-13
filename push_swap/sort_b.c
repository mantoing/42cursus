#include "push_swap.h"

void    init_b_cnt(t_info *info)
{
    info->ra_cnt = 0;
    info->rb_cnt = 0;
    info->pa_cnt = 0;
}

void b_to_a(t_info *info, int size)
{
    int tmp;
    // if (size < 3)
    // {
    //     정렬하고 pa;
    //     return ;
    // }
    init_b_cnt(info);
    get_pivot(info, info->b);
    while (size > 0)
    {
        tmp = info->b->tail->item;
        if (tmp < info->pivot_small)
        {
            rb(info->b);
            info->rb_cnt++;
        }
        else
        {
            pa(info);
            info->pa_cnt++;
            if (tmp < info->pivot_big)
            {
                ra(info->a);
                info->ra_cnt++;
            }
        }
        size--;


}