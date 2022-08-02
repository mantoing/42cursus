/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:40:01 by jaeywon           #+#    #+#             */
/*   Updated: 2022/08/02 17:56:29 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define X_EVENT_KEY_PRESS  2
# define X_EVENT_KEY_RELEASE  3

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "get_next_line.h"

typedef struct s_img
{
	void	*wall;
	void	*tile;
	void	*goal;
	void	*player;
	void	*coll;
}	t_img;

typedef struct s_gameset
{
	int		map_width;
	int		map_height;
	char	*map_line;
	int		count;
	int		coll;
	int		player;
	int		exit;
	int		wall;
	int		tile;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	t_img	img;
}	t_gameset;

int		extension_check(char *s);
void	check_map(t_gameset *gameset);
void	read_map(char *map_file, t_gameset *gameset);
size_t	ft_strlen_without_n(const char *str);
void	print_error(char *s);
char	*ft_strjoin_without_nl(char *s1, char *s2);
void	rendering(t_gameset gameset);
void	image_init(t_gameset gameset, t_img *img);
void	checking_count(t_gameset *gameset);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
void	clear_game(t_gameset gameset);
void	move_w(t_gameset *gameset);
void	move_s(t_gameset *gameset);
void	move_a(t_gameset *gameset);
void	move_d(t_gameset *gameset);

#endif
