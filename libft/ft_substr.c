/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:35:21 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/30 14:40:09 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cp;

	i = -1;
	j = 0;
	cp = malloc(len + 1);
	if (!cp)
		return (0);
	while (s[++i] != '\0')
		if (i >= start && j < len)
			cp[j++] = s[i];
	cp[j] = '\0';
	return (cp);
}
