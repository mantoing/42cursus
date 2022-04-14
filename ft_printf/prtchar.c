/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:41:23 by jaeywon           #+#    #+#             */
/*   Updated: 2022/04/14 17:32:20 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prtchar(char c)
{
	int	res;

	res = 0;
	if (ft_putchar((char)c) == ERR)
		return (ERR);
	return (1);
}
	//else
		//res = ft_putchar(c);
