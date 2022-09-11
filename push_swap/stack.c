#include "push_swap.h"

int    push_top(t_stack *s, int data)
{
    t_link  *new;

	new = (t_link *)malloc(sizeof(t_link));
	if (new == NULL)
		prt_error();
	s->size  += 1;
	if (s->head == NULL)
	{
		s->head = new;
		s->tail = new;
		new-> data = data;
		new->next = NULL;
		new->prev = NULL;
		return (TRUE);
	}
	new->prev = s->tail;
	s->tail->next= new;
	s->tail = new;
	new->next = s->head;
	s->head->prev = new;
	new->data = data;
	return (TRUE);
}

void prt_stack(t_stack *s)
{
	t_link *cur;
	int i;

	i = 0;
	cur = s->head;
	while(i++ < s->size)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}