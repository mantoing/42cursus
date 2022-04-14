/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:41:15 by jaeywon           #+#    #+#             */
/*   Updated: 2022/04/14 15:41:03 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prtstr(char *str)
{
	int	s_len;

	s_len = ft_strlen(str);
	if (!str)
		s_len = (int)write(1, "(null)", 6);
	else
		s_len = ft_putstr(str);
	return (s_len);
}
