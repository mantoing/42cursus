#ifndef	FT_PLINTF_H
# define FT_PLINTF_H

# include <unistd.h>
# include <stdarg.h>

# define ERR -1

int	ft_printf(const char *ag, ...);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	par_arg(va_list ap, char *ag);
int	print_format_type(va_list ap, char type, int *npf);
int	prtchar(char c);
char	chk_base(char type);
int	put_nbr(char type, unsigned long n, char *base);
int	prtnbr(char type, unsigned long n);
int	prtstr(char *str);

#endif
