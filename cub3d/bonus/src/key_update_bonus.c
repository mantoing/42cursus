/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:22:02 by kwpark            #+#    #+#             */
/*   Updated: 2023/03/07 20:01:31 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

static void	move_ws(t_info *info, double dir)
{
	double	move_dir;

	move_dir = dir * info->move_speed;
	if (info->map.map[(int)(info->pos_x + info->dir_x * move_dir)] \
												[(int)info->pos_y] != '1')
		info->pos_x += info->dir_x * move_dir;
	if (info->map.map[(int)info->pos_x] \
						[(int)(info->pos_y + info->dir_y * move_dir)] != '1')
		info->pos_y += info->dir_y * move_dir;
}

static void	move_ad(t_info *info, double dir)
{
	double	move_dir;

	move_dir = dir * info->move_speed;
	if (info->map.map[(int)(info->pos_x + info->plane_x * move_dir)] \
												[(int)info->pos_y] != '1')
		info->pos_x += info->plane_x * move_dir;
	if (info->map.map[(int)info->pos_x] \
						[(int)(info->pos_y + info->plane_y * move_dir)] != '1')
		info->pos_y += info->plane_y * move_dir;
}

static void	rot_dir(t_info *info, double dir)
{
	double	olddirx;
	double	oldplanex;
	double	rot_dir;

	rot_dir = info->rot_speed * dir;
	olddirx = info->dir_x;
	info->dir_x = info->dir_x * cos(rot_dir) - info->dir_y * sin(rot_dir);
	info->dir_y = olddirx * sin(rot_dir) + info->dir_y * cos(rot_dir);
	oldplanex = info->plane_x;
	info->plane_x = info->plane_x * cos(rot_dir) - info->plane_y * sin(rot_dir);
	info->plane_y = oldplanex * sin(rot_dir) + info->plane_y * cos(rot_dir);
}

void	key_update(t_info *info)
{
	if (info->key_w)
		move_ws(info, 1.0);
	if (info->key_s)
		move_ws(info, -1.0);
	if (info->key_a)
		move_ad(info, -1.0);
	if (info->key_d)
		move_ad(info, 1.0);
	if (info->key_ar_l)
		rot_dir(info, 1.0);
	if (info->key_ar_r)
		rot_dir(info, -1.0);
	if (info->key_esc)
		quit_game(info);
}
