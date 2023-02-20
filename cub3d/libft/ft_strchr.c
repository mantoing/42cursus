/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:16:54 by jaeywon           #+#    #+#             */
/*   Updated: 2022/04/05 15:20:55 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
