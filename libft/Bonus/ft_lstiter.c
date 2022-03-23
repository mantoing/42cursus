#include "libft.h"

void	ft_lstiter(t_list *list, void (*f)(void *))
{
	if (!list || !f)
		return ;
	while (list)
	{
		f(list->content);
		list = list -> next;
	}	
}
