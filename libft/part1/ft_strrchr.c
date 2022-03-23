/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:23:52 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/23 14:12:11 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	while (s_len != 0 && s[s_len] != c)
		s_len--;
	if (s[s_len] == c)
		return ((char *)(s + s_len));
	return (0);
}
