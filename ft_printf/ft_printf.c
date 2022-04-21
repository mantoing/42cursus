/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:41:38 by jaeywon           #+#    #+#             */
/*   Updated: 2022/04/21 18:18:30 by jaeywon          ###   ########.fr       */
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
 #include <stdio.h>
 int main(void)
 {
	 ft_printf("내 나이는 %d,%z입니다.", 10);
	 printf("내 나이는 %d,%z입니다.", 10);
	 return (0);
 }