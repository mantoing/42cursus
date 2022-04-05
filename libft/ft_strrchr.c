/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:23:52 by jaeywon           #+#    #+#             */
/*   Updated: 2022/04/05 15:21:17 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*res;
	char		ccc;
	size_t		i;

	i = 0;
	ccc = (char)c;
	res = NULL;
	while (str[i])
	{
		if (str[i] == ccc)
			res = &str[i];
		i++;
	}
	if (str[i] == ccc)
		res = &str[i];
	return ((char *)res);
}
