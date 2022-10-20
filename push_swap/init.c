/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:05:39 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/20 16:36:36 by jaeywon          ###   ########.fr       */
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
	info->num = 0;
}

void	init_a_cnt(t_cnt *count)
{
	count->ra_cnt = 0;
	count->rb_cnt = 0;
	count->pb_cnt = 0;
}

void	init_b_cnt(t_cnt *count)
{
	count->ra_cnt = 0;
	count->rb_cnt = 0;
	count->pa_cnt = 0;
}
