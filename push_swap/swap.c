/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:06:58 by jaeywon           #+#    #+#             */
/*   Updated: 2022/09/20 20:38:46 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *node)
{
	int	tmp;

	tmp = node->tail->item;
	node->tail->item = node->tail->prev->item;
	node->tail->prev->item = tmp;
}

void	sa(t_stack *a)
{
	if (a->size < 2)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (b->size < 2)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_info *node)
{
	sa(node->a);
	sb(node->b);
}
