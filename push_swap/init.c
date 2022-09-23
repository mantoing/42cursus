/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:05:39 by jaeywon           #+#    #+#             */
/*   Updated: 2022/09/23 18:09:08 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	inint_headtail(t_info *info)
{
	info->a->head = NULL;
	info->a->tail = NULL;
	info->b->head = NULL;
	info->b->tail = NULL;
	info->a->size = 0;
	info->b->size = 0;
}
