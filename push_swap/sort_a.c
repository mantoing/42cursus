#include "push_swap.h"

void    init_a_cnt(t_info *info)
{
    info->ra_cnt = 0;
    info->rb_cnt = 0;
    info->pb_cnt = 0;
}

int is_sorted(t_stack *stack, int size, int flag)
{
    t_link *tmp;

    if (size < 2)
        return (TRUE);
    tmp = stack->head;    
    if (flag == 0)
    {
        while (tmp->next != 0)
        {
            if (tmp->item < tmp->next->item)
                return (FALSE);
            tmp = tmp->next;
        }
    }
    else
    {
        while (size-- > 0)
        {
            if (tmp->item < tmp->next->item)
                return (FALSE);
            tmp = tmp->next;    
        }
    } 
    return (TRUE);   
}

void    a_to_b(t_info *info, int size)
{
    int tmp;
    
    init_a_cnt(info);
    get_pivot(info, info->a); 
    if (is_sorted(info->a, size, 0))
        return ;
    // if (size == 2)
    // {
    //     2개일때 하드소트;
    //     return ;
    // }
    // else if (size ==3)
    // {
    //     3개일때 하드소트;
    //     return ;
    // }
    printf("--------------------------------");
    while (size > 0)
    {
        tmp = info->a->tail->item;
        printf("%d\n", tmp);
        if (tmp >= info->pivot_big)
        {
            ra(info->a);
            info->ra_cnt++;
        }
        else
            pb(info);
            info->pb_cnt++;
            if (tmp >= info->pivot_small)
            {
                rb(info->b);
                info->rb_cnt++;
            }
        size--;        
    }
    while (info->ra_cnt-- > 0 && info->rb_cnt-- > 0)
        rrr(info);
    while (info->ra_cnt-- > 0)
        rra(info->a);
    while (info->rb_cnt-- > 0)
        rrb(info->b);
}