/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:51:52 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/30 15:36:19 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_new;
	size_t	len1;
	size_t	len2;

	if (s1 == 0 && s2 == 0)
		return (0);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	s_new = (char *)malloc(sizeof(char) * (len2 + len1 + 1));
	if (s_new == 0)
		return (0);
	ft_memcpy(s_new, s1, len1);
	ft_memcpy(s_new + len1, s2, len2);
	s_new[len1 + len2] = 0;
	return (s_new);
}
