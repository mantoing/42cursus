#include "solong.h"

void    print_error(char *s)
{
    write(2, s, ft_strlen(s));
    exit(1);
}