/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:53:17 by jaeywon           #+#    #+#             */
/*   Updated: 2022/04/05 17:24:08 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numlen(int num)
{
	size_t		cnt;
	long long	n;

	n = num;
	cnt = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static void	trans(char *res, int num, int len)
{
	long long	n;

	n = num;
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	if (n >= 10)
	{
		trans(res, (n / 10), --len);
		res[len] = (n % 10) + '0';
	}
	else
		res[--len] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = numlen(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	trans(res, n, len);
	res[len] = '\0';
	return (res);
}
