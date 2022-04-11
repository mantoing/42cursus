#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t			i;
	unsigned char	a;

	a = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			return ((char *)(str + i));
		i++;
	}
	if (!c)
		return ((char *)(str + i));
	return (0);
}

int	ft_putchar(char c)
{
	return ((int)write(1, &c, 1)); 
}

int	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	return ((int)write(1, &str, len));
}