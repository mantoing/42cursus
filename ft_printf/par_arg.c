#include "ft_printf.h"

int	par_arg(va_list ap, char *ag)
{
	int	npf;

	npf = 0;
	while (*ag)
	{
		if (*ag != '%')
		{
			write(1, ag, 1);
			++npf;
		}
		else
		{
			++ag;
			if (print_format_type(ap, *ag, &npf) == ERR)
				return (ERR);
		}
		++ag;
	}
	return (npf);
}
