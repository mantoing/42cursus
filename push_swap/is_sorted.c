/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:06:00 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/20 16:06:02 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack, int size, int flag)
{
	t_link	*tmp;

	if (size < 2)
		return (TRUE);
	tmp = stack->tail;
	if (flag == 0)
	{
		while (size-- > 1)
		{
			if (tmp->item > tmp->prev->item)
				return (FALSE);
			tmp = tmp->prev;
		}
	}
	else
	{
		while (size-- > 1)
		{
			if (tmp->item < tmp->prev->item)
				return (FALSE);
			tmp = tmp->prev;
		}
	}
	return (TRUE);
}
