#include "libft.h"

char	*split_dup(char const *str, size_t len)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = 0;
	return (s);
}

size_t	split_len(char const *str, char c)
{
	size_t		len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}



void	*all_free(char **str, size_t l)
{
	size_t	i;

	i = 0;
	while (str[i] && i <= l)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**arr_malloc(char *str, char c)
{
	size_t	cnt;
	char	**arr;

	cnt = 0;
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str != c)
		{
			cnt++;
			while (*str != c && *str)
				str++;
		}
		else
			str++;
	}
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	return (arr);
}

char	**ft_split(char const *str, char c)
{
	size_t		i;
	size_t		len;
	char		**arr;

	i = 0;
	len = 0;
	arr = arr_malloc((char *)str, c);
	if (!arr)
		return (0);
	while (*str)
	{
		if (*str != c)
		{
			len = split_len(str, c);
			arr[i] = *split_dup(str, len);
			str += len;
			len = 0;
			if (!arr[i++])
				return (all_free(arr, i));
		}
		else
			str++;
	}
	arr[i] = 0;
	return (arr);
}
