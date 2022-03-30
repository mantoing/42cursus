/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:45:38 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/30 14:46:19 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*back;

	if (!list || !back)
		return ;
	back = *list;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	while (back -> next)
		back = back -> next;
	back -> next = new;
}
