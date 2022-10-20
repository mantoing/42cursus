/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:47:19 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/20 15:47:21 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cal_inequality(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->tail->item;
	b = stack->tail->prev->item;
	c = stack->head->item;
	if (a > b && b > c)
		return (1);
	if (a > b && b < c && a > c)
		return (2);
	else if (a < b && b > c && a > c)
		return (3);
	else if (a > b && b < c && a < c)
		return (4);
	else if (a < b && b > c && a < c)
		return (5);
	else
		return (0);
}

void	only_three_sort(t_stack *stack)
{
	if (cal_inequality(stack) == 1)
	{
		sa(stack);
		rra(stack);
	}
	else if (cal_inequality(stack) == 2)
		ra(stack);
	else if (cal_inequality(stack) == 3)
		rra(stack);
	else if (cal_inequality(stack) == 4)
		sa(stack);
	else if (cal_inequality(stack) == 5)
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else
		return ;
}

void	for_only_pivot(t_info *info, int *arr)
{
	int		i;
	int		center;

	center = arr[2];
	i = 0;
	while (i < 5)
	{
		if (x(info->a, 0) < arr[2])
			pb(info);
		else
			ra(info->a);
		i++;
	}
}

void	only_five_sort(t_info *info)
{
	int		*arr;
	int		i;
	t_link	*cur;

	i = 0;
	arr = (int *)malloc(5 * sizeof(int));
	if (!arr)
		prt_error(0);
	cur = info->a->tail;
	while (i < 5)
	{
		arr[i] = cur->item;
		cur = cur->prev;
		i++;
	}
	arr_qsort(arr, 0, --i);
	for_only_pivot(info, arr);
	only_three_sort(info->a);
	sort_two(info, 1);
	free(arr);
}
