/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:27:20 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/23 17:32:42 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cp;

	i = 0;
	cp = (char *)haystack;
	if (needle[i] == '\0')
		return (cp);
	while (i < len && cp[i] != '\0')
	{
		j = 0;
		if (cp[i] == needle[j])
		{
			while ((cp[i + j] == needle[j])
				&& (needle[j] != '\0') && (i + j < len))
				j++;
			if (needle[j] == '\0')
				return (&cp[i]);
		}
		i++;
	}
	return (0);
}
