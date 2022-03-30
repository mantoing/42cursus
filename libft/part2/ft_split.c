#include "libft.h"

char	*split_dup(char const *str, size_t len)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (i < len)
	{
		s[i] = str[i];
		i++; 
	}
	return (s);	
}

size_t	ft_countstr(char const *str, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] && str[i] != c)
				c++;
			cnt++;	 
		}
		else
			i++;
	}
	return (cnt);
}
size_t	split_len(char const *str, char c)
{
	size_t	len;
	
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);	
}

char	**errorcheck(void)
{
	char	**let;

	let = (char **)malloc(sizeof(char *));
	if (!let)
		return (NULL);
	let[0] = 0;
	return (let); 	
}
 
char	**ft_split(char const *str, char c)
{
	size_t	strnum;
	size_t	i;
	size_t	len;
	char	**ret;

	if (!str || *str == '\0')
		return (errorcheck());
	i = 0;
	len = 0;
	strnum = ft_countstr(str, c);
	ret = (char **)malloc(sizeof(char *) * (strnum * 1));
	if (ret== NULL)
		return (NULL);
	while (i < strnum)
	{
		while (str[0] == c)
			str++;
		len = split_len(str, c);
		ret[i] = split_dup(str, len);
		str = str + len;
		i++;	 	
	}
	ret[i] = 0;
	return (ret);	
}
