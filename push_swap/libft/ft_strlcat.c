/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:08:18 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/30 15:17:54 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	srclen;
	size_t	destlen;
	char	*tmp;

	tmp = (char *)src;
	srclen = ft_strlen(tmp);
	destlen = ft_strlen(dest);
	if (destsize < destlen)
		return (srclen + destsize);
	ft_strlcpy(dest + destlen, src, destsize - destlen);
	return (srclen + destlen);
}
