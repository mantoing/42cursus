#include "solong.h"

void    image_init(t_gameset *gameset, t_img *img)
{
    int height;
    int width;

    img->img_coll = mlx_xpm_file_to_image(gameset->mlx, "./images/coll.xpm", &height, &width);
    img->img_player = mlx_xpm_file_to_image(gameset->mlx, "./images/dino.xpm", &height, &width);
    img->img_goal = mlx_xpm_file_to_image(gameset->mlx, "./images/goal.xpm", &height, &width);
    img->img_tile = mlx_xpm_file_to_image(gameset->mlx, "./images/tile00.xpm", &height, &width);
    img->img_wall = mlx_xpm_file_to_image(gameset->mlx, "./images/tile01.xpm", &height, &width);
}

void draw_image(t_gameset *gameset, t_img *img)
{
    int h;
    int w;

    h = 0;
    while (h < gameset->map_height)
    {
        w = 0;
        while (w < gameset->map_width)
        {
            if (gameset->map_line[h * gameset->map_width + w] == '1')
                mlx_put_image_to_window(gameset->mlx, gameset->win, img->img_wall, h * 64, w * 64);
            else if (gameset->map_line[h * gameset->map_width + w] == 'C')
                mlx_put_image_to_window(gameset->mlx, gameset->win, img->img_coll, h * 64, w * 64);
            else if (gameset->map_line[h * gameset->map_width + w] == 'E')
                mlx_put_image_to_window(gameset->mlx, gameset->win, img->img_goal, h * 64, w * 64);
            else if (gameset->map_line[h * gameset->map_width + w] == 'P')
                mlx_put_image_to_window(gameset->mlx, gameset->win, img->img_player, h * 64, w * 64);
            w++;               
        }
        h++;
    } 
}