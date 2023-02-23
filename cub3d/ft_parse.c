/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:29:11 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/23 22:17:04 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_dir_player(char c)
{
	if (c == 'N')
		return (N);
	else if (c == 'S')
		return (S);
	else if (c == 'E')
		return (E);
	else if (c == 'W')
		return (W);
	return (0);
}

static void	check_element_dir(t_info *info, char *line)
{
	int		i;
	char	line_c;

	i = 0 ;
	if (check_valid_map(line) == 1)
		print_err("map elements error\n");
	while (line[i])
	{
		line_c = line[i];
		if (line_c == 'N' || line_c == 'S' || line_c == 'E' || line_c == 'W')
		{
			if (info->player.status != 0)
				print_err("we only need one player\n");
			info->player.status = set_dir_player(line_c);
		}
	}
	if (info->map.w < i)
		info->map.w = i;
	if (info->player.status == 0)
	{
		printf("wdlblab%d\n", info->map.count);
		info->player.status = info->map.count;
	}
}

static void	check_type(t_info *info, char *line)
{
	int		i;
	t_map	*m;

	m = &info->map;
	if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3) || \
			!ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
		check_dir(&info->map, line, line[0]);
	else if (!ft_strncmp("F ", line, 2) || !ft_strncmp("C ", line, 3))
		check_color(&info->map, &line);
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '0' || line[i] == '1')
	{
		if (!m->dir_ea || !m->dir_no || !m->dir_so || !m->dir_we || \
			!(m->f_color == -1) || !(m->c_color == -1))
			print_err("map texture or color error\n");
		check_element_dir(info, line);
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
		check_type(info, line);
		free(line);
	}
	load_map(name, info);
	return (0);
}
