#include <stdio.h>
#include "solong.h"
int quit_game(t_gameset *gameset)
{
    mlx_destroy_window(gameset->mlx, gameset->win);
    exit(0);
}

void    set_gameinit(t_gameset *gameset)
{
    gameset->map_width = 0;
    gameset->map_height = 0;
    gameset->map_line = NULL;
    gameset->move_cnt = 0;
    gameset->mlx = NULL;
    gameset->win = NULL;
}

int	extension_check(char *s)
{
	int	s_len;

	s_len = ft_strlen(s);
	if (s_len < 4)
		return (0);
	if (!(s[s_len - 1] == 'r' && s[s_len - 2] == 'e' \
		&& s[s_len - 3] == 'b' && s[s_len - 4] == '.'))
		return (0);
	return (1);
}

int press_key(int key, t_gameset *gameset)
{
	if (key == 13)
		move_w(gameset);
	else if (key == 0)
		move_a(gameset);
	else if (key == 1)
		move_s(gameset);
	else if (key == 2)
		move_d(gameset);
	else if (key == 53)
		exit(0);
	return (0);	
}

int main(int ac, char **av)
{
    t_gameset   gameset;
    //t_img       img;

    if (ac != 2 || extension_check(av[1]) == 0)
        print_error("ac Error\n");
    set_gameinit(&gameset);
    read_map(av[1], &gameset);
    check_map(&gameset);    
    gameset.mlx = mlx_init();
    gameset.win = mlx_new_window(gameset.mlx, gameset.map_width * 64, gameset.map_height * 64, "so_long");
	rendering(gameset);
	mlx_key_hook(gameset.win, mlx_key_handle, 0);
    mlx_loop(gameset.mlx);
    return (0);
}