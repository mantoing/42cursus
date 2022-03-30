/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:14:00 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/30 15:10:38 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int b, size_t len)
{
	size_t			i;
	unsigned char	*ret;

	i = 0;
	ret = (unsigned char *)ptr;
	while (i < len)
	{
		ret[i] = (unsigned char)b;
		i++;
	}
	return (ptr);
}
