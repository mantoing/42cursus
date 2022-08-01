/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:24:07 by jaeywon           #+#    #+#             */
/*   Updated: 2022/08/01 19:48:37 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	read_map(char *map_file, t_gameset *g)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(map_file, O_RDONLY);
	if (fd <= 0)
		print_error("File open fail\n");
	line = get_next_line(fd);
	if (!line)
		print_error("Unvalid map\n");
	g->map_width = ft_strlen(line) - 1;
	g->map_line = line;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			tmp = g->map_line;
			g->map_line = ft_strjoin_without_nl(tmp, line);
			free(tmp);
			free(line);
		}
		g->map_height++;
	}
	close(fd);
}

void	prt_check_map(char line, char num)
{
	if (line != num)
		print_error("Fail/Map must be surrounded by walls.");
}

void	check_map(t_gameset *g)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(g->map_line))
	{
		if (i < g->map_width)
			prt_check_map(g->map_line[i], '1');
		else if (i % g->map_width == 0 || i % g->map_width == g->map_width - 1)
			prt_check_map(g->map_line[i], '1');
		else if (i > ((int)ft_strlen(g->map_line) - g->map_width))
			prt_check_map(g->map_line[i], '1');
		i++;
	}
	if (g->map_height * g->map_width != (int)ft_strlen(g->map_line))
		print_error("Map must be rectangular\n");
}
