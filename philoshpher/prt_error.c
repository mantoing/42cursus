/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:43:54 by jaeywon           #+#    #+#             */
/*   Updated: 2022/10/24 21:35:25 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	prt_error(int code)
{
	if (code == 1)
		write(1, "AC ERROR\n", 10);
	else if (code == 2)
		write(1, "MALLOC ERROR\n", 13);
	else if (code == 3)
		write(1, "MUTEX ERROR\n", 13);
	return (code);	
}