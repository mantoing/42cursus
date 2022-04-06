/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:51:52 by jaeywon           #+#    #+#             */
/*   Updated: 2022/04/06 16:20:06 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_new;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (0);
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	s_new = (char *)malloc(sizeof(char) * (l2 + l1 + 1));
	if (s_new == 0)
		return (0);
	ft_memcpy(s_new, s1, l1);
	ft_memcpy(s_new + l1, s2, l2);
	s_new[l1 + l2] = 0;
	return (s_new);
}
