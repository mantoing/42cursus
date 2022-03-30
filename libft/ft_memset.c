/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:14:00 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/23 15:09:04 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int b, size_t len)
{
	int				i;
	unsigned char	*ret;

	i = 0;
	ret = (unsigned char *)ptr;
	while (i < len)
	{
		ret[i] = (unsigned char *)b;
		i++;
	}
	return (ptr);
}
