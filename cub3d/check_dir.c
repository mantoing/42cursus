/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:17:21 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/23 19:18:26 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*check_texture(char *line)
{
	int		fd;
	char	*ret;

	ret = NULL;
	fd = 0;
	line += 2;
	while (ft_isspace(*line))
		line++;
	fd = open(line, O_RDONLY);
	if (fd < 0)
		print_err("fail check texture\n");
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
		print_err("fail dir error\n");
	return (1);
}
