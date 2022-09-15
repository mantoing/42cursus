#include "push_swap.h"

void    rra(t_stack *stack_a)
{
    t_link *tmp;

    if (stack_a->size == 2)
    	sa(stack_a);
    else if (stack_a->size > 2)
    {
		tmp = stack_a->head;
		stack_a->head = stack_a->head->next;
		stack_a->head->prev = NULL;
		tmp = stack_a->tail->next;
		tmp->prev = stack_a->tail;
		stack_a->tail = tmp;
		write(1, "rra\n", 4);
    }
}

void    rrb(t_stack *stack_b)
{
    t_link *tmp;

    if (stack_b->size == 2)
    	sa(stack_b);
    else if (stack_b->size > 2)
    {
		tmp = stack_b->head;
		stack_b->head = stack_b->head->next;
		stack_b->head->prev = NULL;
		tmp = stack_b->tail->next;
		tmp->prev = stack_b->tail;
		stack_b->tail = tmp;
		write(1, "rrb\n", 4);
    }
}

void	rrr(t_info *stack)
{
	rra(stack->a);
	rrb(stack->b);
}