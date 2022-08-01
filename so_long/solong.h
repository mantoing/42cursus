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


typedef struct  s_img
{
    void    *img_wall;
    void    *img_tile;
    void    *img_goal;
    void    *img_player;
    void    *img_coll;
}   t_img;

typedef struct s_gameset
{
    int map_width;
    int map_height;
    char    *map_line;
    int count;
    int	coll;
    int	player;
    int	exit;
	int	wall;
	int tile;
	int x;
	int y;
    void    *mlx;
    void    *win;
    t_img   img;
}   t_gameset;

int	extension_check(char *s);
void check_map(t_gameset *gameset);
void    read_map(char *map_file, t_gameset *gameset);
void    print_error(char *s);
char	*ft_strjoin_without_NL(char *s1, char *s2);
void    rendering(t_gameset gameset);
void    image_init(t_gameset gameset, t_img *img);
void checking_count(t_gameset *gameset);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
void    clear_game(t_gameset gameset);
void    move_w(t_gameset *gameset);
void    move_s(t_gameset *gameset);
void    move_a(t_gameset *gameset);
void    move_d(t_gameset *gameset);

#endif