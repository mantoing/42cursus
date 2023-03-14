/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:39:42 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/07 20:01:28 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

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
	player->status = -1;
	player->x = 0;
	player->y = 0;
}

static void	init_dir_vec(t_info *info, int dir_sign, int plane_sign)
{
	if (info->player.status == N || info->player.status == S)
	{
		info->dir_x = 1.0 * dir_sign;
		info->dir_y = 0.0 * dir_sign;
		info->plane_x = 0.0 * plane_sign;
		info->plane_y = 0.66 * plane_sign;
	}
	else if (info->player.status == E || info->player.status == W)
	{
		info->dir_x = 0.0 * dir_sign;
		info->dir_y = 1.0 * dir_sign;
		info->plane_x = 0.66 * plane_sign;
		info->plane_y = 0.0 * plane_sign;
	}
}

void	init_pos(t_info *info)
{
	int	dir_sign;
	int	plane_sign;

	info->pos_x = info->player.x;
	info->pos_y = info->player.y;
	dir_sign = 1;
	plane_sign = 1;
	if (info->player.status == N)
		dir_sign = -1;
	else if (info->player.status == S)
		plane_sign = -1;
	else if (info->player.status == W)
	{
		dir_sign = -1;
		plane_sign = -1;
	}
	init_dir_vec(info, dir_sign, plane_sign);
}

void	init_key(t_info *info)
{
	info->move_speed = 0.03;
	info->rot_speed = 0.03;
	info->re_buf = 0;
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_ar_l = 0;
	info->key_ar_r = 0;
	info->key_esc = 0;
}
