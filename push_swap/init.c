#include "push_swap.h"

void	inint_headtail(t_info *info)
{
	info->a->head = NULL;
	info->a->tail = NULL;
	info->b->head = NULL;
	info->b->tail = NULL;
	info->a->size = 0;
}