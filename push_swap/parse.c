/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:06:18 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/20 15:53:29 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(int *arr, int len)
{
	int	i;

	i = 1;
	if (len < 2)
		return ;
	while (i < len)
	{
		if (arr[i] == arr[i - 1])
			prt_error(0);
		i++;
	}
}

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
			prt_error(0);
		i--;
	}
	if (a->size == 0)
		prt_error(0);
	return (0);
}

int	one_arg(char *s, t_stack *a)
{
	char		**str;
	int			len;
	int			i;
	long long	temp;

	temp = ft_atoi(s);
	str = ft_split(s, ' ');
	len = lengthofarray(str);
	while (len >= 1)
	{
		if (to_int(a, str[len - 1]) == FALSE)
			prt_error(0);
		if (temp > INT_MAX || temp < INT_MIN)
			prt_error(0);
		len--;
	}
	return (0);
}
