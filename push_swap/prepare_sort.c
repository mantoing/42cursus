/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:53:45 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/20 15:54:25 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_swap(int *arr, t_pivot *pv)
{
	if (pv->i > pv->j)
	{
		pv->tmp = arr[pv->j];
		arr[pv->j] = arr[pv->pivot];
		arr[pv->pivot] = pv->tmp;
	}
	else
	{
		pv->tmp = arr[pv->i];
		arr[pv->i] = arr[pv->j];
		arr[pv->j] = pv->tmp;
	}
}

void	init_pivot(t_pivot *pv, int start, int end)
{
	pv->pivot = start;
	pv->i = pv->pivot + 1;
	pv->j = end;
}

void	arr_qsort(int *arr, int start, int end)
{
	t_pivot	pv;

	init_pivot(&pv, start, end);
	if (start >= end)
		return ;
	while (pv.i <= pv.j)
	{
		while (pv.i <= end && arr[pv.i] <= arr[pv.pivot])
			pv.i++;
		while (pv.j > start && arr[pv.j] >= arr[pv.pivot])
			pv.j--;
		arr_swap(arr, &pv);
	}
	arr_qsort(arr, start, pv.j - 1);
	arr_qsort(arr, pv.j + 1, end);
}

void	get_pivot(t_info *info, t_stack *stack, int ssize)
{
	int		*arr;
	int		i;
	t_link	*cur;

	if (stack->size < 4)
		return ;
	i = 0;
	arr = (int *)malloc(ssize * sizeof(int));
	if (!arr)
		prt_error(0);
	cur = stack->tail;
	while (i < ssize)
	{
		arr[i] = cur->item;
		cur = cur->prev;
		i++;
	}
	arr_qsort(arr, 0, --i);
	info->pivot_small = arr[(int)(ssize / 3)];
	info->pivot_big = arr[2 * (int)(ssize / 3)];
	free(arr);
}
