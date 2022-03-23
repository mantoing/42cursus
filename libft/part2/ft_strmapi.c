/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:19:26 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/23 17:42:37 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*res;
	int		size;
	int		i;
	
	if (!str || !f)
		return (NULL);
	i = 0;
	size = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	while (str[i] != '\0')
	{
		res[i] = f(i, str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}