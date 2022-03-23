#include "libft.h"

t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list -> next)
	{
		list = list -> next;
	}
	return (list);	
}