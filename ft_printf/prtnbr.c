#include "ft_printf.h"

char	*chk_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'P')
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");	
}

int	put_nbr(char type, unsigned long n, char *base)
{
	int res;
	int temp;
	unsigned long	nbr;

	temp = 0;
	if (type == 'd' || type == 'i' || type == 'u')
	{
		nbr = 10;
		if (n >= nbr)
			temp = put_nbr(type, n / nbr, base);
	}
	else
	{
		nbr = 16;
		if (n >= nbr)
			temp = put_nbr(type, n / nbr, base);
	}
	if (temp == ERR)
		return (ERR);
	res = temp;
	temp = write(1, &base[n / nbr], 1);
	if (temp == ERR)
		return (ERR);
	res = res + temp;
	return (res);		
}

int	prtnbr(char type, unsigned long n)
{
	int	tmp;
	int res;
	char *base;

	base = chk_base(type);
	res = 0;
	if (type == 'P')
	{
		res = write(1, "0x", 2);		
	}
	else if (type == 'd' || type == 'i' || type == 'u')
	{
		res = write(1, "-", 1);
		n *= -1;
	}
	if (res == ERR)
		return (ERR);
	tmp = put_nbr(type, n, base);
	if (tmp == ERR)
		return (ERR);
	res = res + tmp;
	return (res); 				
}
