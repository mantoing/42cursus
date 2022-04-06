/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:26:28 by jaeywon           #+#    #+#             */
/*   Updated: 2022/04/06 16:21:37 by jaeywon          ###   ########.fr       */
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

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		len;
	char		**arr;

	i = 0;
	len = 0;
	arr = malloc_arr((char *)s, c);
	if (!arr)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = split_len(s, c);
			arr[i] = split_dup(s, len);
			s += len;
			len = 0;
			if (!arr[i++])
				return (allfree(arr, i));
		}
		else
			s++;
	}
	arr[i] = 0;
	return (arr);
}
