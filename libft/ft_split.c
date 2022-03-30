/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:26:28 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/30 16:27:32 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_ret(char *s, char c)
{
	size_t	cnt;
	char	**ret;

	cnt = 0;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!ret)
		return (NULL);
	return (ret);
}

static char	*ft_malloc_ret_n(char *str, char *start, char *end)
{
	int	i;

	str = (char *)malloc(end - start + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < end - start)
		str[i] = start[i];
	str[i] = 0;
	return (str);
}

static void	*free_all(char **str, size_t l)
{
	size_t	i;

	i = 0;
	while (str[i] && i < l)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**ret;
	char	*start;
	size_t	i;

	ret = ft_malloc_ret((char *)str, c);
	if (!ret)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			start = (char *)str;
			while (*str && *str != c)
				str++;
			ret[i] = ft_malloc_ret_n(ret[i], start, (char *)str);
			if (!ret[i++])
				return (free_all(ret, i));
		}
		else
			str++;
	}
	ret[i] = 0;
	return (ret);
}
