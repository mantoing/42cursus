#include "ft_printf.h"

int	print_format_type(va_list ap, char type, int *npf)
{
	int res;

	if (type == 'd' || type == 'i')
		res = prtnbr(type, va_arg(ap, int));
	else if (type == 'u' || type == 'x' || type == 'X')
		res = prtnbr(type, va_arg(ap, unsigned int));	
	else if (type == 'P')
		res = prtnbr(type, va_arg(ap, unsigned long));
	else if (type == 's')
		res = prtstr(va_arg(ap, char *));		
	else if (type == 'c')
		res = prtchar((char)va_arg(ap, int));
	else if (type == '%')
		res = prtchar('%');
	else
		return (ERR);
	*npf += res;
	return  (res);	
}
