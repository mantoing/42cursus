/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:59:22 by jaeywon           #+#    #+#             */
/*   Updated: 2022/09/15 21:46:34 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_link
{
    int item;
    struct s_link *next;
    struct s_link *prev;
}    t_link;

typedef struct s_stack
{
	t_link  *head;
    t_link  *tail;
    t_link data;
	int	size;
}	t_stack;

typedef struct s_info
{
    t_stack *a;
    t_stack *b;
    int max_size;
    int max;
    int min;
}	t_info;

int check_error_av(int ac, char **av);
void	inint_headtail(t_info *info);
void	init_stack(int ac, char **av, t_info *info);
void    prt_error(void);
int    push_top(t_stack *deque, int data);
void prt_stack(t_stack *s);
int	many_args(char **av, int i, t_stack *a);
int	one_arg(char *s, t_stack *a);
long	lengthofarray(char **arr);
int	pop_top(t_stack *s);
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_info *node);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_info *stack);
int pa(t_info *sta);
int pb(t_info *sta);
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void	rrr(t_info *stack);

#endif