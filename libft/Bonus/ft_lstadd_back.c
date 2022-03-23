#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*back;

	if (!list || !back)
		return ;
	back = *list;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	while (back -> next)
		back = back -> next;
	back ->next = new;		
}