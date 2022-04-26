/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:41:38 by jaeywon           #+#    #+#             */
/*   Updated: 2022/04/21 16:27:33 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *ag, ...)
{
	int		npf;
	va_list	ap;
	char	*s;

	if (!ag)
		return (ERR);
	va_start (ap, ag);
	s = (char *)ag;
	npf = par_arg(ap, s);
	va_end(ap);
	return (npf);
}
