/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:39:42 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/24 17:07:25 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->count = 0;
	map->check = 1;
	map->f_color = -1;
	map->c_color = -1;
	map->start = 0;
	map->w = 0;
	map->h = 0;
	map->map = NULL;
	map->dir_ea = NULL;
	map->dir_no = NULL;
	map->dir_so = NULL;
	map->dir_we = NULL;
}

void	init_player(t_player *player)
{
	player->status = 0;
	player->x = 0;
	player->y = 0;
}
