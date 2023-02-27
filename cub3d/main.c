/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:08:11 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/27 18:19:36 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_name(char *s)
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

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2 || (check_map_name(av[1]) == 0))
		print_err("ac error\n");
	ft_parse(av[1], &info);
	//그래픽관련 함수들이 써져 있어야 하는 부분
	printf("%s\n", info.map.dir_no);
	printf("%s\n", info.map.dir_so);
	printf("%s\n", info.map.dir_ea);
	printf("%s\n", info.map.dir_we);
	printf("celling color: %d\n", info.map.c_color);
	printf("floor color: %d\n", info.map.f_color);
	for (int y = 0; y < info.map.h; y++)
	{
		for(int x = 0; x < info.map.w; x++)
			printf("%c ", info.map.map[y][x]);
		printf("\n");
	}
	return (0);
}
