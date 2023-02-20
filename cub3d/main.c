/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:08:11 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/20 16:38:41 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_name(char *s)
{
	int	s_len;

	s_len = ft_strlen(s);
	if (s_len < 4)
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

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2 || (check_map_name(av[1]) == 1))
		print_err("ac error\n");
	//ft_init(); 구조체정보 초기화 처리해주는 부분
	ft_parse(av[1], &info);
}