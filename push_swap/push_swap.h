/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:59:22 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/20 17:37:01 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_link
{
	int				item;
	struct s_link	*next;
	struct s_link	*prev;
}	t_link;

typedef struct s_stack
{
	t_link	*head;
	t_link	*tail;
	t_link	data;
	int		size;
}	t_stack;

typedef struct s_info
{
	t_stack	*a;
	t_stack	*b;
	int		max_size;
	int		max;
	int		min;
	int		pivot_small;
	int		pivot_big;
	int		num;

}	t_info;

typedef struct s_pivot
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;
}	t_pivot;

typedef struct s_cnt
{
	int		ra_cnt;
	int		pb_cnt;
	int		rb_cnt;
	int		pa_cnt;
}	t_cnt;

int		check_error_av(int ac, char **av);
void	inint_headtail(t_info *info);
void	init_stack(int ac, char **av, t_info *info);
void	prt_error(int ac);
int		push_top(t_stack *deque, int data);
int		many_args(char **av, int i, t_stack *a);
int		one_arg(char *s, t_stack *a);
long	lengthofarray(char **arr);
int		pop_top(t_stack *s);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
int		pa(t_info *sta);
int		pb(t_info *sta);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	get_pivot(t_info *info, t_stack *stack, int ssize);
void	check_duplicate(int *arr, int len);
void	a_to_b(t_info *info, int size);
void	b_to_a(t_info *info, int size);
void	sort_two(t_info *info, int flag);
void	sort_three(t_info *info, int flag);
void	a_three_sort(t_info *info);
void	b_three_sort(t_info *info);
int		is_sorted(t_stack *stack, int size, int flag);
void	check_rrr(t_info *info, int ra_cnt, int rb_cnt);
void	first_put_arr(t_stack *stack, int ssize);
void	arr_qsort(int *arr, int start, int end);
int		err_check(char **av);
void	only_five_sort(t_info *info);
void	only_three_sort(t_stack *stack);
void	init_a_cnt(t_cnt *count);
void	init_b_cnt(t_cnt *count);
int		x(t_stack *stack, int prev_cnt);
void	do_b_to_a(t_info *info, int size);
void	do_a_to_b(t_info *info, int size);
void	split_anum(t_info *info, t_cnt *count);
void	zerosplit_anum(t_info *info, t_cnt *count);

#endif