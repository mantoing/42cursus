#include "push_swap.h"

void    push_top(t_info *deque, int data)
{
    t_stack  *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (deque->tailer == NULL)
	{
		deque->header = new;
		deque->tailer = new;
		new-> data = data;
		new->next = NULL;
		new->prev = NULL;
		return ;
	}
	deque->header->prev = new;
	new->next = deque->header;
	deque->header = new;
	new->data = data;
	new->prev = NULL;
}

int	pop_top(t_info *deque)
{
	int ret;
	t_stack	*cur;

	ret = 0;
	cur = NULL;
	ret = deque->header->data;
	deque->header->next->prev = NULL;
	cur = deque->header;
	deque->header = deque->header->next;
	free(cur);
	return (ret);
}