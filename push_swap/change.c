/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:14:10 by jaeywon           #+#    #+#             */
/*   Updated: 2022/09/30 20:35:59 by jaeywon          ###   ########.fr       */
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
            if (i < stack->a->size / 2 && i >= 0) //스택의 제일 윗값이 i+chunk보다 크기때문에 수많은 ra를 해야함 따라서 stack의 top이 i+chunk보다 큰 경우일 때 i가 a스택 크기의 절반보다 작다면 rra로 반대로 뒤집어 버리면 불필요한 연산을 줄일 수 있다. 
                rra(stack);
            el0se
                ra(stack);
        }
            
    }
}

void    b_to_a(t_info *stack)
{

}