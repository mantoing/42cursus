#include "ft_printf.h"

int	prtchar(char c)
{
	int	res;

	res = 0;
	if ((int)ft_putchar((char)c) == ERR)
		return (ERR);
	else
		res = ft_putchar(c);
	return (res);		
}