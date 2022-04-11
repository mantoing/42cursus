#include "ft_printf.h"

int	prtstr(char *str)
{
	int	s_len;

	s_len = ft_strlen(str);
	if (!str)
		s_len = (int)write(1, "(null)", 1);
	else
		s_len = ft_putstr(str);
	return (s_len);		
}