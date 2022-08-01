/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:35:19 by jaeywon           #+#    #+#             */
/*   Updated: 2022/08/01 19:38:18 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_w(t_gameset *g)
{
	int	x;
	int	y;

	x = g->x;
	y = g->y - 1;
	if (g->map_line[g->map_width * y + x] != '1')
	{
		if (g->map_line[g->map_width * y + x] == 'C')
			g->coll--;
		if (g->map_line[g->map_width * y + x] == 'E' && g->coll != 0)
			return ;
		if (g->map_line[g->map_width * y + x] == 'E')
			clear_game(*g);
		g->map_line[g->map_width * y + x] = 'P';
		g->map_line[g->map_width * g->y + g->x] = '0';
		g->x = x;
		g->y = y;
		g->count++;
		ft_putnbr_fd(g->count, 1);
		write(1, " steps. \n", 9);
		rendering(*g);
	}
}

void	move_s(t_gameset *g)
{
	int	x;
	int	y;

	x = g->x;
	y = g->y + 1;
	if (g->map_line[g->map_width * y + x] != '1')
	{
		if (g->map_line[g->map_width * y + x] == 'C')
			g->coll--;
		if (g->map_line[g->map_width * y + x] == 'E' && g->coll != 0)
			return ;
		if (g->map_line[g->map_width * y + x] == 'E')
			clear_game(*g);
		g->map_line[g->map_width * y + x] = 'P';
		g->map_line[g->map_width * g->y + g->x] = '0';
		g->x = x;
		g->y = y;
		g->count++;
		ft_putnbr_fd(g->count, 1);
		write(1, " steps. \n", 9);
		rendering(*g);
	}
}

void	move_a(t_gameset *g)
{
	int	x;
	int	y;

	x = g->x - 1;
	y = g->y;
	if (g->map_line[g->map_width * y + x] != '1')
	{
		if (g->map_line[g->map_width * y + x] == 'C')
			g->coll--;
		if (g->map_line[g->map_width * y + x] == 'E' && g->coll != 0)
			return ;
		if (g->map_line[g->map_width * y + x] == 'E')
			clear_game(*g);
		g->map_line[g->map_width * y + x] = 'P';
		g->map_line[g->map_width * g->y + g->x] = '0';
		g->x = x;
		g->y = y;
		g->count++;
		ft_putnbr_fd(g->count, 1);
		write(1, " steps. \n", 9);
		rendering(*g);
	}
}

void	move_d(t_gameset *g)
{
	int	x;
	int	y;

	x = g->x + 1;
	y = g->y;
	if (g->map_line[g->map_width * y + x] != '1')
	{
		if (g->map_line[g->map_width * y + x] == 'C')
			g->coll--;
		if (g->map_line[g->map_width * y + x] == 'E' && g->coll != 0)
			return ;
		if (g->map_line[g->map_width * y + x] == 'E')
			clear_game(*g);
		g->map_line[g->map_width * y + x] = 'P';
		g->map_line[g->map_width * g->y + g->x] = '0';
		g->x = x;
		g->y = y;
		g->count++;
		ft_putnbr_fd(g->count, 1);
		write(1, " steps. \n", 9);
		rendering(*g);
	}
}
