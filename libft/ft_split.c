/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:26:28 by jaeywon           #+#    #+#             */
/*   Updated: 2022/04/05 14:45:39 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**malloc_arr(char *str, char c)
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

char	*split_dup(char const *s, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

size_t	split_len(char const *str, char c)
{
	size_t		len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

void	*allfree(char **str, size_t l)
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

char	**ft_split(char const *str, char c)
{
	size_t		i;
	size_t		len;
	char		**arr;

	i = 0;
	len = 0;
	arr = malloc_arr((char *)str, c);
	if (!arr)
		return (0);
	while (*str)
	{
		if (*str != c)
		{
			len = split_len(str, c);
			arr[i] = split_dup(str, len);
			str += len;
			len = 0;
			if (!arr[i++])
				return (allfree(arr, i));
		}
		else
			str++;
	}
	arr[i] = 0;
	return (arr);
}
