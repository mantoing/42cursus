/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:39:32 by jaeywon           #+#    #+#             */
/*   Updated: 2022/08/01 19:39:46 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

void	clear_game(t_gameset gameset)
{
	ft_putnbr_fd(gameset.count, 1);
	write(1, " steps. Clear!\n", 16);
	exit(0);
}
