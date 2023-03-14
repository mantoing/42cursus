/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:42:08 by kwpark            #+#    #+#             */
/*   Updated: 2023/03/07 20:01:39 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	get_texnum(t_raycast *rc)
{
	if (rc->side == 1)
	{
		if (rc->raydir_y > 0)
			return (W);
		else
			return (E);
	}
	else
	{
		if (rc->raydir_x > 0)
			return (N);
		else
			return (S);
	}
}

void	camera_buf_flush(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < (int)HEIGHT / 2)
				info->buf[i][j] = info->map.c_color;
			else
				info->buf[i][j] = info->map.f_color;
			j++;
		}
		i++;
	}
}

void	draw_texture(t_info *info, t_raycast *rc, t_tex *tex, int x)
{
	int	y;

	y = rc->draw_start;
	while (y < rc->draw_end)
	{
		tex->tex_y = (int)tex->tex_pos & (TEXHEIGHT - 1);
		tex->tex_pos += tex->step;
		tex->color = \
			info->texture[tex->texnum][TEXHEIGHT * tex->tex_y + tex->tex_x];
		info->buf[y][x] = tex->color;
		info->re_buf = 1;
		y++;
	}
}
