/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:59:22 by jaeywon           #+#    #+#             */
/*   Updated: 2022/09/07 21:19:48 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
    int data;
    struct s_stack *next;
    struct s_stack *prev; 
}    t_stack;

typedef struct s_info
{
    t_stack	*header;
    t_stack	*tailer;
	t_stack	*a;
    t_stack *b;
	int	item;
}	t_info;

void    prt_error(void);
void    push_top(t_info *deque, int data);

#endif