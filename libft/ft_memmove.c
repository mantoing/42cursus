/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:13:53 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/23 15:07:56 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*dest_c;

	if (!dest && !src)
		return (NULL);
	dest_c = (char *)dest;
	i = 0;
	if (dest > src)
	{
		while (len--)
			*(dest_c + len) = *(char *)(src + len);
	}
	else
	{
		while (len--)
			*dest_c++ = *(char *)src++;
	}
	return (dest);
}
