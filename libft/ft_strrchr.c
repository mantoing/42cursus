/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:23:52 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/30 15:18:41 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	s_len;
	char	*tmp;

	tmp = (char *)str;
	s_len = ft_strlen(tmp);
	while (s_len != 0 && str[s_len] != c)
		s_len--;
	if (str[s_len] == c)
		return ((char *)(str + s_len));
	return (0);
}
