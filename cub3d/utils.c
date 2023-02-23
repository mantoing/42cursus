/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:33:12 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/23 21:15:41 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	if (!dst)
		return (0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (src[i])
		i++;
	return (i);
}

static int	check_char(const char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (0);
		str++;
	}
	return (1);
}

int	check_valid_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (check_char("01NSEW ", line[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
