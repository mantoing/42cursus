/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:23:54 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/27 08:01:35 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_space_valid(char **map, int x, int y)
{
	if ((map[y][x + 1] != '1' && map[y][x + 1] != ' ') || \
		(map[y][x - 1] != '1' && map[y][x - 1] != ' ') || \
		(map[y + 1][x] != '1' && map[y + 1][x] != ' ') || \
		(map[y - 1][x] != '1' && map[y - 1][x] != ' '))
		print_err("map space somethig wrong\n");
}

static void	check_map_edge(char **map, int w, int h)
{
	int	i;

	i = -1;
	while (++i < h)
	{
		if ((map[i][0] != '1' && map[i][0] != ' ') || (map[i][w - 1] != '1' && \
		map[i][w - 1] != ' '))
			print_err("invalid side edge of map\n");
		if ((map[i][0] == ' ' && map[i][1] == '0') || (map[h - 1][i] == ' ' && \
		map[h - 2][i] == '0'))
			print_err("invalid side edge of map\n");
	}
	i = -1;
	while (++i < w)
	{
		if ((map[0][i] != '1' && map[0][i] != ' ') || (map[h - 1][i] != '1' && \
		map[h - 2][i] != ' '))
			print_err("invalid layer edge of map\n");
		if ((map[0][i] == ' ' && map[1][i] == '0') || (map[h - 1][i] == ' ' && \
		map[h - 2][i] == '0'))
			print_err("invalid layer edge of map\n");
	}
}

void	check_wall(char **map, int w, int h)
{
	int	x;
	int	y;

	if (w < 3 || h < 3)
		print_err("map is too small\n");
	printf("height %d\n", h);
	check_map_edge(map, w, h);
	y = 0;
	while (++y < h - 1)
	{
		x = 0;
		while (++x < w - 1)
		{
			if (map[y][x] == ' ')
				check_space_valid(map, x, y);
			else if (map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'N'\
			|| map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
				continue ;
			else
				print_err("map point valid is wrong\n");
		}
	}
}