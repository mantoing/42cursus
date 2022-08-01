#include "solong.h"

void    elements_init(t_gameset *gameset)
{
    gameset->player = 0;
    gameset->tile = 0;
    gameset->exit = 0;
    gameset->coll = 0;
    gameset->count = 0;
}

void    counting_element(t_gameset *gameset, int c, int i)
{
    if (c == 'P')
    {
        gameset->x = i % gameset->map_width;
        gameset->y = i / gameset->map_width;
        gameset->player++;
    }
    else if (c == 'C')
        gameset->coll++;
    else if (c == 'E')
        gameset->exit++;
    else if (c == '0' || c == '1')
        ;
    else
        print_error("Invalid map element\n");            
}

void checking_count(t_gameset *gameset)
{
    int i;

    i = -1;
    elements_init(gameset);
    while (gameset->map_line[++i])
        counting_element(gameset, gameset->map_line[i], i);
    if (gameset->exit == 0)
        print_error("Map must have at least one exit");
    else if (gameset->coll == 0)
        print_error("Map must have at least one collectible");
    else if (gameset->player != 1)
        print_error("Map must have one player\n");            
}