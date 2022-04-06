/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:35:21 by jaeywon           #+#    #+#             */
/*   Updated: 2022/04/06 16:23:43 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sec;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen((char *)s);
	if ((size_t)start >= s_len)
		return (ft_strdup(""));
	if (s_len - (size_t)start > len)
		sec = (char *)malloc(sizeof(char) * (len + 1));
	else
		sec = (char *)malloc(sizeof(char) * (s_len - start + 1));
	if (!sec)
		return (NULL);
	while (s[i] && i < len)
	{
		sec[i] = s[start];
		i++;
		start++;
	}
	sec[i] = '\0';
	return (sec);
}
