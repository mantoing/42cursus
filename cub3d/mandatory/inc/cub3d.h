/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:10:20 by kwpark            #+#    #+#             */
/*   Updated: 2023/03/07 17:38:47 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../../libft/libft.h"
# include "../../minilibx/mlx.h"
# include "key_macos.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT	17
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define WIDTH 640
# define HEIGHT 480

# define N	0
# define W	1
# define S	2
# define E	3

typedef struct s_raycast
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_raycast;

typedef struct s_tex
{
	int		texnum;
	double	wallx;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;
}				t_tex;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_line;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_map
{
	char	**map;
	int		count;
	int		check;
	int		f_color;
	int		c_color;
	int		start;
	int		w;
	int		h;
	char	*dir_no;
	char	*dir_so;
	char	*dir_we;
	char	*dir_ea;
}	t_map;

typedef struct s_player
{
	int		status;
	double	x;
	double	y;
}	t_player;

typedef struct s_info
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	double		move_speed;
	double		rot_speed;
	t_img		img;
	int			buf[HEIGHT][WIDTH];
	int			**texture;
	int			re_buf;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_ar_l;
	int			key_ar_r;
	int			key_esc;
	t_map		map;
	t_player	player;
}	t_info;

void	raycasting(t_info *info);
void	key_update(t_info *info);
int		get_texnum(t_raycast *rc);
void	camera_buf_flush(t_info *info);
void	draw_texture(t_info *info, t_raycast *rc, t_tex *tex, int x);
void	init_arr(int **arr, int size1, int size2, int value);
void	load_texture(t_info *info);
void	draw_buffer(t_info *info);
void	print_err(char *str);
int		ft_isspace(char c);
int		ft_parse(char *name, t_info *info);
int		check_dir(t_map *map, char *line, char c);
void	check_color(t_map *map, char *line, char c);
void	init_map(t_map *map);
int		check_valid_map(char *line);
size_t	ft_strcpy(char *dst, const char *src);
void	load_map(char *name, t_info *info);
void	check_wall(char **map, int w, int h);
void	init_player(t_player *player);
void	print_err(char *str);
int		check_map_name(char *s);
void	init_key(t_info *info);
void	init_pos(t_info *info);
int		quit_game(t_info *info);

#endif