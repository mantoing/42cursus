/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:33:29 by jaeywon           #+#    #+#             */
/*   Updated: 2022/09/01 16:33:44 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static	int	isspace(char c)
{
	if (c == '\t' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	while (isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		return (-1);
	}
	result = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}
