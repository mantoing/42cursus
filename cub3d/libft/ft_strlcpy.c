/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:50:17 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/30 15:16:28 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	srclen;
	char	*tmp;

	tmp = (char *)src;
	i = 0;
	srclen = ft_strlen(tmp);
	if (destsize == 0)
		return (srclen);
	while (src[i] && i < (destsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (srclen);
}
