/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:29:11 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/22 12:47:07 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_type(t_map *map, char *line)
{
	int	i;

	if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3) || \
			!ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
		check_dir(&map, line, line[0]);
	else if (!ft_strncmp("F ", line, 2) || !ft_strncmp("C ", line, 3))
		check_color(&map, &line);
	while (ft_isspace(line))
	i = 0;
	if (line[i] == '0' || line[i] == '1')
	{
		if (!map->dir_ea || !map->dir_no || !map->dir_so || !map->dir_we || \
				map->f_color == -1 || map->c_color == -1)
			print_err("map texture or color error\n");
	}
}

int	ft_parse(char *name, t_info *info)
{
	char	*line;
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		print_err("open fail\n");
	init_map(info->map);
	while (info->map.check == 1)
	{
		info->map.check = get_next_line(fd, &line);
		if (info->map.check == -1)
			print_err("fail read map\n");
		info->map.count += 1;
		check_type(&info->map, line); 
	}
}
