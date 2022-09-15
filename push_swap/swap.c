#include "push_swap.h"

void swap(t_stack *node)
{
    int tmp;

    tmp = node->tail->item;
    node->tail->item = node->tail->prev->item;
    node->tail->prev->item = tmp;
}

void sa(t_stack *a)
{
    if (a->size < 2)
        return ;
    swap(a);
    write(1, "sa\n", 3);

}

void sb(t_stack *b)
{
    if (b->size < 2)
        return ;
    swap(b);
    write(1, "sb\n", 3);

}

void ss(t_info *node)
{
    sa(node->a);
    sb(node->b);
}