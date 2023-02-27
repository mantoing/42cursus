/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:05:16 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/24 17:36:47 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

# define N 1
# define S 2
# define E 3
# define W 4

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
	int	status;
	int	x;
	int	y;
}	t_player;

typedef struct s_info
{
	// void	*mlx;
	// void	*win;
	t_player	player;
	t_map		map;
}	t_info;

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
#endif