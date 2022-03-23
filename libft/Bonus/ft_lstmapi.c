#include "libft.h"

char *ft_lstmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (!str || !f)
		return (NULL);
	ret = malloc(sizeof (char) * (ft_strlen((char *)str) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = f(i , str[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);		
}