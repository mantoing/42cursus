#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_gameset
{
    int map_width;
    int map_height;
    char    *map_line;
    int move_cnt;
    int oj_cnt;
    int oj_max;
    void    *mlx;
    void    *win;
}   t_gameset;

int	extension_check(char *s);
void    set_gameinit(t_gameset *gameset);
int    key_press(int key, void*p);
int quit_game(t_gameset *gameset);
void check_map(t_gameset *gameset);
void    read_map(char *map_file, t_gameset *gameset);
void    prt_check_map(char line, char num);
void    print_error(char *s);

#endif
