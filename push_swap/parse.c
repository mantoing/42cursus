#include "push_swap.h"

// int check_duplicate()

static int	to_int(t_stack *a, char *st)
{
	if (ft_strlen(st) >= 12)
		return (FALSE);
	else if (ft_strlen(st) == 11 && *st == '+')
	{
		if (st[1] > '2' || ft_atoi_push(st) < 0)
			return (FALSE);
	}
	else if (ft_strlen(st) == 11 && *st == '-')
	{
		if (st[1] > '2' || ft_atoi_push(st) > 0)
			return (FALSE);
	}
	else if (ft_strlen(st) == 10 && *st != '+' && *st != '-')
	{
		if (st[0] > '2' || ft_atoi_push(st) < 0)
			return (FALSE);
	}
	if (st[0] != '0' && ft_atoi_push(st) == 0)
		return (FALSE);
	// printf("%s, %d ", st, ft_atoi_push(st));
	push_top(a, ft_atoi_push(st));
	return (TRUE);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (FALSE);
	else
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

	str = ft_split(s, ' ');
	i = -1;
	while (str[++i] != NULL)
	{
		if (to_int(a, str[i]) == FALSE)
			prt_error();
	}
	return (0);
}
