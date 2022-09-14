#include "push_swap.h"
#include <string.h>

// int check_duplicate()

long	lengthofarray(char **arr)
{
	long	size;
	
	size = 0;
	while (arr[size])
		size++;
	return (size);
}


static int	to_int(t_stack *a, char *st)
{
	if (ft_strlen(st) >= 12)
		return (FALSE);
	else if (ft_strlen(st) == 11 && *st == '+')
	{
		if (st[1] > '2' || ft_atoi(st) < 0)
			return (FALSE);
	}
	else if (ft_strlen(st) == 11 && *st == '-')
	{
		if (st[1] > '2' || ft_atoi(st) > 0)
			return (FALSE);
	}
	else if (ft_strlen(st) == 10 && *st != '+' && *st != '-')
	{
		if (st[0] > '2' || ft_atoi(st) < 0)
			return (FALSE);
	}
	if (st[0] != '0' && ft_atoi(st) == 0)
		return (FALSE);
	push_top(a, ft_atoi(st));
	return (TRUE);
}

int	many_args(char **av, int i, t_stack *a)
{
	while (i >= 1)
	{
		if (one_arg(av[i], a))
			prt_error();
		i--;
	}
	return (0);
}

int	one_arg(char *s, t_stack *a)
{
	char **str;
	int len;

	str = ft_split(s, ' ');
	len = lengthofarray(str);
	while (len >= 1)
	{
		if (to_int(a, str[len -1]) == FALSE)
		prt_error();
		len--;
	}
	return (0);
}
