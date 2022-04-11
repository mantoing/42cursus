#include "ft_printf.h"

int	ft_printf(const char *ag, ...)
{
	int	npf;
	va_list	ap;
	char *s;

	if (!ag)
		return (ERR);
	va_start (ap, ag);
	s = (char *)ag;
	if (!ft_strchr(s, '%'))
		npf = (int)write(1, s, ft_strlen(s));
	else
		npf = par_arg(ap, s);
	va_end(ap);
	return (npf);
}
