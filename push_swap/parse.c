#include "push_swap.h"
#include <string.h>
// int check_duplicate()

// long	lengthofarray(const char *arr)
// {
// 	long	size;

// 	size = 0;
// 	while (*arr)
// 	{
// 		size += 1;
// 		arr += 1;
// 	}

// 	return (size);
// }


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
	// printf("%s, %d ", st, ft_atoi(st));
	push_top(a, ft_atoi(st));
	return (TRUE);
}

int	many_args(char **av, int i, t_stack *a)
{
	while (i >= 1)
	{
		// printf("cnt\n");
		if (one_arg(av[i], a))
			prt_error();
		i--;
	}
	return (0);
}

int	one_arg(char *s, t_stack *a)
{
	char **str;
	int	i;
	// int len;

	str = ft_split(s, ' ');
	// len = lengthofarray(s);
	// printf("%d = func\n", len);
	// printf("%lu = sizeof\n", sizeof(str));
	i = -1;
	while (str[++i] != NULL)
	{
		if (to_int(a, str[i]) == FALSE)
		prt_error();
	}
	return (0);
}
