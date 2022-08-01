#include "solong.h"

void    move_w(t_gameset *gameset)
{
    int x;
    int y;

    x = gameset->x;
    y = gameset->y - 1;
    if (gameset->map_line[gameset->map_width * y + x] != '1')
        {
            if (gameset->map_line[gameset->map_width * y + x] == 'C')
                gameset->coll--;
            if (gameset->map_line[gameset->map_width * y + x] == 'E' && gameset->coll != 0)
                return ;
            if (gameset->map_line[gameset->map_width * y + x] == 'E')
                clear_game(*gameset); 
            gameset->map_line[gameset->map_width * y + x] = 'P';
            gameset->map_line[gameset->map_width * gameset->y + gameset->x] = '0';
            gameset->x = x;
            gameset->y = y;
            gameset->count++;
            ft_putnbr_fd(gameset->count, 1);
            write(1, " steps. \n", 9);
            rendering(*gameset);
        }
}

void    move_s(t_gameset *gameset)
{
    int x;
    int y;

    x = gameset->x;
    y = gameset->y + 1;
    if (gameset->map_line[gameset->map_width * y + x] != '1')
        {
            if (gameset->map_line[gameset->map_width * y + x] == 'C')
                gameset->coll--;
            if (gameset->map_line[gameset->map_width * y + x] == 'E' && gameset->coll != 0)
                return ;
            if (gameset->map_line[gameset->map_width * y + x] == 'E')
                clear_game(*gameset); 
            gameset->map_line[gameset->map_width * y + x] = 'P';
            gameset->map_line[gameset->map_width * gameset->y + gameset->x] = '0';
            gameset->x = x;
            gameset->y = y;
            gameset->count++;
            ft_putnbr_fd(gameset->count, 1);
            write(1, " steps. \n", 9);
            rendering(*gameset);
        }
}

void    move_a(t_gameset *gameset)
{
    int x;
    int y;

    x = gameset->x - 1;
    y = gameset->y;
    if (gameset->map_line[gameset->map_width * y + x] != '1')
        {
            if (gameset->map_line[gameset->map_width * y + x] == 'C')
                gameset->coll--;
            if (gameset->map_line[gameset->map_width * y + x] == 'E' && gameset->coll != 0)
                return ;
            if (gameset->map_line[gameset->map_width * y + x] == 'E')
                clear_game(*gameset); 
            gameset->map_line[gameset->map_width * y + x] = 'P';
            gameset->map_line[gameset->map_width * gameset->y + gameset->x] = '0';
            gameset->x = x;
            gameset->y = y;
            gameset->count++;
            ft_putnbr_fd(gameset->count, 1);
            write(1, " steps. \n", 9);
            rendering(*gameset);
        }
}

void    move_d(t_gameset *gameset)
{
    int x;
    int y;

    x = gameset->x + 1;
    y = gameset->y;
    if (gameset->map_line[gameset->map_width * y + x] != '1')
        {
            if (gameset->map_line[gameset->map_width * y + x] == 'C')
                gameset->coll--;
            if (gameset->map_line[gameset->map_width * y + x] == 'E' && gameset->coll != 0)
                return ;
            if (gameset->map_line[gameset->map_width * y + x] == 'E')
                clear_game(*gameset); 
            gameset->map_line[gameset->map_width * y + x] = 'P';
            gameset->map_line[gameset->map_width * gameset->y + gameset->x] = '0';
            gameset->x = x;
            gameset->y = y;
            gameset->count++;
            ft_putnbr_fd(gameset->count, 1);
            write(1, " steps. \n", 9);
            rendering(*gameset);
        }
}