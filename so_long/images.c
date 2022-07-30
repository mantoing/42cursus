#include "solong.h"

void    image_init(t_gameset gameset, t_img *img)
{
    int height;
    int width;

    img->img_coll = mlx_xpm_file_to_image(gameset.mlx, "./images/coll.xpm", &height, &width);
    img->img_player = mlx_xpm_file_to_image(gameset.mlx, "./images/dino.xpm", &height, &width);
    img->img_goal = mlx_xpm_file_to_image(gameset.mlx, "./images/goal.xpm", &height, &width);
    img->img_tile = mlx_xpm_file_to_image(gameset.mlx, "./images/tile00.xpm", &height, &width);
    img->img_wall = mlx_xpm_file_to_image(gameset.mlx, "./images/tile01.xpm", &height, &width);
}

void    draw_img(t_gameset gameset, t_img img)
{
    int h;
    int w;

    h = -1;
    while (h++ < gameset.map_height)
    {
        w = -1;
        while (w++ < gameset.map_width)
        {
            mlx_put_image_to_window(gameset.mlx, gameset.win, img.img_tile, w * 64, h *64);
            if (gameset.map_line[h * gameset.map_width + w] == '1')
                mlx_put_image_to_window(gameset.mlx, gameset.win, img.img_wall, w * 64, h * 64);
            else if (gameset.map_line[h * gameset.map_width + w] == 'C')
                mlx_put_image_to_window(gameset.mlx, gameset.win, img.img_coll, w * 64, h * 64);
            else if (gameset.map_line[h * gameset.map_width + w] == 'E')
                mlx_put_image_to_window(gameset.mlx, gameset.win, img.img_goal, w * 64, h * 64);
            else if (gameset.map_line[h * gameset.map_width + w] == 'P')
                mlx_put_image_to_window(gameset.mlx, gameset.win, img.img_player, w * 64, h * 64);
        }
    }
}

void    rendering(t_gameset gameset)
{
    t_img   img;

    image_init(gameset, &img);
    draw_img(gameset, img);

}