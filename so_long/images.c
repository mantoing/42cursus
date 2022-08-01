/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:53:32 by jaeywon           #+#    #+#             */
/*   Updated: 2022/08/01 19:15:43 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	image_init(t_gameset g, t_img *img)
{	
	int	height;
	int	width;

	img->coll = mlx_xpm_file_to_image(g.mlx, \
										"./images/coll.xpm", &height, &width);
	img->player = mlx_xpm_file_to_image(g.mlx, \
										"./images/dino.xpm", &height, &width);
	img->goal = mlx_xpm_file_to_image(g.mlx, \
										"./images/goal.xpm", &height, &width);
	img->tile = mlx_xpm_file_to_image(g.mlx, \
										"./images/tile00.xpm", &height, &width);
	img->wall = mlx_xpm_file_to_image(g.mlx, \
										"./images/tile01.xpm", &height, &width);
}

void	put_img(t_gameset *g, void *img, int w, int h)
{
	mlx_put_image_to_window(g->mlx, g->win, img, w, h);
}

void	draw_img(t_gameset g, t_img i)
{
	int	h;
	int	w;

	h = -1;
	while (h++ < g.map_height)
	{
		w = -1;
		while (w++ < g.map_width)
		{
			mlx_put_image_to_window(g.mlx, g.win, i.tile, w * 64, h * 64);
			if (g.map_line[h * g.map_width + w] == '1')
				mlx_put_image_to_window(g.mlx, g.win, i.wall, w * 64, h * 64);
			else if (g.map_line[h * g.map_width + w] == 'C')
				mlx_put_image_to_window(g.mlx, g.win, i.coll, w * 64, h * 64);
			else if (g.map_line[h * g.map_width + w] == 'E')
				mlx_put_image_to_window(g.mlx, g.win, i.goal, w * 64, h * 64);
			else if (g.map_line[h * g.map_width + w] == 'P')
				mlx_put_image_to_window(g.mlx, g.win, i.player, w * 64, h * 64);
		}
	}
}

void	rendering(t_gameset gameset)
{
	t_img	img;

	image_init(gameset, &img);
	draw_img(gameset, img);
}
