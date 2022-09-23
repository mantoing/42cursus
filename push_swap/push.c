/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:49:24 by jaeywon           #+#    #+#             */
/*   Updated: 2022/09/20 20:18:25 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_info *sta)
{
	int	data;

	data = pop_top(sta->b);
	if (sta->b->head == NULL)
		return (FALSE);
	if (push_top(sta->a, data) == FALSE)
		return (FALSE);
	write(1, "pa\n", 3);
	return (TRUE);
}

int	pb(t_info *sta)
{
	int	data;

	data = pop_top(sta->a);
	if (sta->a->head == NULL)
		return (FALSE);
	if (push_top(sta->b, data) == FALSE)
		return (FALSE);
	write(1, "pb\n", 3);
	return (TRUE);
}
