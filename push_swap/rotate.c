#include "push_swap.h"

void    ra(t_stack *stack_a)
{
    t_link *tmp;

    if (stack_a->size == 2)
        sa(stack_a);
    else if (stack_a->size > 2)
    {
        tmp = stack_a->tail;
        stack_a->tail = stack_a->tail->prev;
        stack_a->tail->next = NULL;
        stack_a->head->prev = tmp;
        tmp->next = stack_a->head;
        stack_a->head = tmp;
        write(1, "ra\n", 3); 
    }
}

void    rb(t_stack *stack_b)
{
    t_link *tmp;

    if (stack_b->size == 2)
        sb(stack_b);
    else if (stack_b->size > 2)
    {
        tmp = stack_b->tail;
        stack_b->tail = stack_b->tail->prev;
        stack_b->tail->next = NULL;
        stack_b->head->prev = tmp;
        tmp->next = stack_b->head;
        stack_b->head = tmp;
        write(1, "rb\n", 3); 
    }
}

void    rr(t_info *stack)
{
    ra(stack->a);
    rb(stack->b);
}