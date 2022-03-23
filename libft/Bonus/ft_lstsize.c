#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list -> next;
	}
	return (i);
}