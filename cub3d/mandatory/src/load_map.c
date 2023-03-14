/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:52:07 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/07 19:58:52 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	make_arr_and_change_space(int fd, t_info *info, char **arr)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while (i < info->map.h)
	{
		info->map.check = get_next_line(fd, &line);
		if (info->map.check == -1)
			print_err("fail read map\n");
		tmp = (char *)malloc(sizeof(char) * (info->map.w + 1));
		if (!tmp)
			print_err("malloc error: make space\n");
		ft_memset(tmp, ' ', info->map.w);
		tmp[info->map.w] = '\0';
		ft_strcpy(tmp, line);
		arr[i] = tmp;
		free(line);
		line = NULL;
		i++;
	}
}

static void	pass_already_done_map(int fd, t_info *info)
{
	int		i;
	char	*line;

	i = 0;
	while (i < info->map.start -1)
	{
		info->map.check = get_next_line(fd, &line);
		if (info->map.check == -1)
			print_err("fail read map\n");
		free(line);
		line = NULL;
		i++;
	}
}

static void	set_pos_player(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' \
			|| map[i][j] == 'W')
			{
				player->x = i + 0.5;
				player->y = j + 0.5;
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	load_map(char *name, t_info *info)
{
	char	**tmp;
	int		fd;

	if (info->player.status == -1)
		print_err("cannot found player\n");
	if (info->map.start == 0)
		print_err("cannot found map\n");
	info->map.h = info->map.count - info->map.start + 1;
	tmp = (char **)malloc(sizeof(char *) * (info->map.h + 1));
	if (!tmp)
		print_err("malloc error : load_map.c\n");
	fd = open(name, O_RDONLY);
	if (fd == -1)
		print_err("cannot load map\n");
	pass_already_done_map(fd, info);
	make_arr_and_change_space(fd, info, tmp);
	tmp[info->map.h] = 0;
	info->map.map = tmp;
	check_wall(info->map.map, info->map.w, info->map.h);
	set_pos_player(info->map.map, &info->player);
}
