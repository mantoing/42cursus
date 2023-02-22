/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:18:28 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/22 00:11:06 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

static int	change_str_to_int(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			print_err("color error\n");
		result *= 10;
		result += str[i] - '0';
	}
	if (result < 0 || result > 255)
		print_err("color is not 0~255\n");
	return (result);
}

static int	color_parse(char *line)
{
	char	**str;
	int		rgb_r;
	int		rgb_g;
	int		rgb_b;
	int		color;

	str = ft_split(line, ',');
	if (!str)
		print_err("malloc error\n" );
	if (str[0] == NULL || str[1] == NULL || str[2] == NULL)
		print_err("COLOR imformations split dailed\n");
	str[2][ft_strlen(str[2]) - 1] = '\0';
	rgb_r = change_str_to_int(str[0]);
	rgb_g = change_str_to_int(str[1]);
	rgb_b = change_str_to_int(str[2]);
	color = (rgb_r << 16) + (rgb_g << 8) + rgb_b;
	free_str(str);
	return (color);
}

void	check_color(t_map *map, char **line)
{
	line += 2;
	while ((*line)[0] != '\n')
	{
		if (!ft_strncmp(*line, "F ", 2))
			map->f_color = color_parse(&(*line)[2]);
		else if (!ft_strncmp(*line, "C ", 2))
			map->c_color = color_parse(&(*line)[2]);
		else
			print_err("F and C are not seperated\n");
		free(*line);
	}
}
