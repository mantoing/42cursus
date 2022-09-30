/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:14:10 by jaeywon           #+#    #+#             */
/*   Updated: 2022/09/30 18:40:00 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void a_to_b(t_info *stack)
{
    int i;
    int chunk;

    chunk = 0.000000053 * (stack->a->size) * (stack->a->size) + 0.03 * (stack->a->size) + 14.5;
    i = 0;
    while (stack->a->size != 0)
    {
        if (stack->a->tail <= i)
        {
            pb(stack);
            i++;
        }
        else if (i < stack->a->tail && stack->a->tail <= i + chunk)
        {
            pb(stack);
            rb(stack);
            i++;
        }
        else if (i + chunk < stack->a->tail)
        {
            if (i < stack->a->size / 2 && i >= 0)
                rra(stack);
            else
                ra(stack);
        }
            
    }
}

void    b_to_a(t_info *stack)
{

}