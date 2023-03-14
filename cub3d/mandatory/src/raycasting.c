/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:21:28 by kwpark            #+#    #+#             */
/*   Updated: 2023/03/06 09:43:53 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	set_dda_vars(t_info *info, t_raycast *rc)
{
	rc->map_x = (int)(info->pos_x);
	rc->map_y = (int)(info->pos_y);
	rc->deltadist_x = fabs(1 / rc->raydir_x);
	rc->deltadist_y = fabs(1 / rc->raydir_y);
	rc->hit = 0;
	if (rc->raydir_x < 0)
	{
		rc->step_x = -1;
		rc->sidedist_x = (info->pos_x - rc->map_x) * rc->deltadist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->sidedist_x = (rc->map_x + 1.0 - info->pos_x) * rc->deltadist_x;
	}
	if (rc->raydir_y < 0)
	{
		rc->step_y = -1;
		rc->sidedist_y = (info->pos_y - rc->map_y) * rc->deltadist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->sidedist_y = (rc->map_y + 1.0 - info->pos_y) * rc->deltadist_y;
	}
}

static void	dda_algorithm(t_info *info, t_raycast *rc)
{
	while (rc->hit == 0)
	{
		if (rc->sidedist_x < rc->sidedist_y)
		{
			rc->sidedist_x += rc->deltadist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->sidedist_y += rc->deltadist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (info->map.map[rc->map_x][rc->map_y] == '1')
			rc->hit = 1;
	}
}

static void	set_texture(t_info *info, t_raycast *rc, int x)
{
	t_tex	tex;

	rc->draw_start = -rc->line_height / 2 + HEIGHT / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_height / 2 + HEIGHT / 2;
	if (rc->draw_end >= HEIGHT)
		rc->draw_end = HEIGHT - 1;
	tex.texnum = get_texnum(rc);
	if (rc->side == 0)
		tex.wallx = info->pos_y + rc->perpwalldist * rc->raydir_y;
	else
		tex.wallx = info->pos_x + rc->perpwalldist * rc->raydir_x;
	tex.wallx -= floor(tex.wallx);
	tex.tex_x = (int)(tex.wallx * (double)TEXWIDTH);
	if (rc->side == 0 && rc->raydir_x > 0)
		tex.tex_x = TEXWIDTH - tex.tex_x - 1;
	if (rc->side == 1 && rc->raydir_y < 0)
		tex.tex_x = TEXWIDTH - tex.tex_x - 1;
	tex.step = 1.0 * TEXHEIGHT / rc->line_height;
	tex.tex_pos = \
		(rc->draw_start - HEIGHT / 2 + rc->line_height / 2) * tex.step;
	draw_texture(info, rc, &tex, x);
}

static void	get_perp(t_info *info, t_raycast *rc)
{
	if (rc->side == 0)
		rc->perpwalldist = \
			(rc->map_x - info->pos_x + (1 - rc->step_x) / 2) / rc->raydir_x;
	else
		rc->perpwalldist = \
			(rc->map_y - info->pos_y + (1 - rc->step_y) / 2) / rc->raydir_y;
	rc->line_height = (int)(HEIGHT / rc->perpwalldist);
}

void	raycasting(t_info *info)
{
	int			x;
	t_raycast	rc;

	x = 0;
	if (info->re_buf == 1)
		camera_buf_flush(info);
	while (x < WIDTH)
	{
		rc.camera_x = 2 * x / (double)WIDTH - 1;
		rc.raydir_x = info->dir_x + info->plane_x * rc.camera_x;
		rc.raydir_y = info->dir_y + info->plane_y * rc.camera_x;
		set_dda_vars(info, &rc);
		dda_algorithm(info, &rc);
		get_perp(info, &rc);
		set_texture(info, &rc, x);
		x++;
	}
}
