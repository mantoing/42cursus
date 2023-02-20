/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:29:11 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/20 19:44:39 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*check_texture(char *line)
{
	int		fd;
	char	*ret;

	ret = NULL;
	fd = 0;
	line += 2;
	while (ft_isspace(line))
		line++;
	fd = open(line, O_RDONLY);
	if (fd < 0)
		print_err("fail check texture");
	close(fd);
	ret = ft_strdup(line);
	return (ret);
}

int	check_dir(t_map *map, char *line, char c)
{
	char	*tmp;

	tmp = check_texture(line);
	if (c == 'N' && map->dir_no == NULL)
		map->dir_no = tmp;
	else if (c == 'S' && map->dir_so == NULL)
		map->dir_so = tmp;
	else if (c == 'W' && map->dir_we == NULL)
		map->dir_we = tmp;
	else if (c == 'E' && map->dir_ea == NULL)
		map->dir_ea = tmp;
	else
		print_err("fail dir error");
	return (1);
}

int	check_type(t_map *map, char *line)
{
	if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3) || \
			!ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
		check_dir(&map, line, line[0]);
	else if (!ft_strncmp("F ", line, 2) || !ft_strncmp("C ", line, 3))
		check_color();
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
			print_err("fail read map");
		info->map.count += 1;
		check_type(&info->map, line);
	}
	
}