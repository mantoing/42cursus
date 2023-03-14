/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:08:11 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/06 10:45:31 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_map_name(char *s)
{
	int	s_len;

	s_len = ft_strlen(s);
	if (s_len < 5)
		return (0);
	if (!(s[s_len - 1] == 'b' && s[s_len - 2] == 'u' \
		&& s[s_len - 3] == 'c' && s[s_len - 4] == '.'))
		return (0);
	return (1);
}

void	print_err(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	exit(1);
}
