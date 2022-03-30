/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:30:42 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/30 14:30:37 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntlen(int n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		n *= -1;
		res++;
	}
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static char	*trans(char *ret, long n, int len)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		n *= -1;
		ret[0] = '-';
		cnt++;
	}
	while (len > res)
	{
		ret[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;

	len = ft_cntlen(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret = trans(ret, (long)n, len);
	ret[len] = 0;
	return (ret);
}
