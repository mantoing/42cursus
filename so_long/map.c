#include "solong.h"

void    read_map(char *map_file, t_gameset *gameset)
{
    int fd;
    char    *line;
    char    *tmp;

    fd = open(map_file, O_RDONLY);
    if (fd <= 0)
        print_error("File open fail\n");
    line = get_next_line(fd);
    if (!line)
        print_error("Unvalid map\n");
    gameset->map_width = ft_strlen(line) - 1;
    //printf("%d\n ", gameset->map_width);
    gameset->map_line = line;
    while (line)
    {       
        line = get_next_line(fd);
        if (line)
        {
            tmp = gameset->map_line;
            gameset->map_line = ft_strjoin_without_NL(tmp, line);
            free(tmp);
            free(line);
        }
        gameset->map_height++;
        //printf("%s", gameset->map_line);
        //printf("%d ", gameset->map_height);
    }
     printf("%s", gameset->map_line);
    if (gameset->map_height * gameset->map_width != (int)ft_strlen(gameset->map_line))
        print_error("Map must be rectangular\n");
    close(fd);
}

void    prt_check_map(char line, char num)
{
    if (line != num)
                print_error("Fail/Map must be surrounded by walls.");
}

void check_map(t_gameset *gameset)
{
    int i;

    i = 0;
    printf("0\n");
    while(i < (int)ft_strlen(gameset->map_line))
    {
        if (i < gameset->map_width) //첫번째 줄 유효성 검사
            prt_check_map(gameset->map_line[i], '1');
        else if (i % gameset->map_width == 0 || i % gameset->map_width == gameset->map_width - 1) //두번째줄 유효성 검사
            prt_check_map(gameset->map_line[i], '1');
        else if (i > ((int)ft_strlen(gameset->map_line) - gameset->map_width))
            prt_check_map(gameset->map_line[i], '1');   
        i++;      
    }
}