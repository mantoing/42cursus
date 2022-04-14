/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:41:30 by jaeywon           #+#    #+#             */
/*   Updated: 2022/04/14 17:30:34 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	par_arg(va_list ap, char *ag)
{
	int	npf;

	npf = 0;
	while (*ag)
	{
		if (*ag != '%')
		{
			write(1, ag, 1);
			++npf;
		}
		else
		{
			++ag;
			if (print_format_type(ap, *ag, &npf) == ERR)
				return (ERR);
		}
		++ag;
	}
	return (npf);
}
