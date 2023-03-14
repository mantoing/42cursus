/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:18:28 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/07 18:31:11 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	int	i;
	int	result;

	result = 0;
	i = -1;
	while (ft_isspace(*str))
		str++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			print_err("color error\n");
		result *= 10;
		result += str[i] - '0';
	}
	if (i > 3 || result < 0 || result > 255)
		print_err("color is not 0~255\n");
	return (result);
}

static int	get_strnum(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	color_parse(char *line)
{
	char	**str;
	int		rgb_r;
	int		rgb_g;
	int		rgb_b;
	int		color;

	str = ft_split(line, ',');
	if (!str || !str[0] || !str[1] || !str[2] || get_strnum(str) != 3)
	{
		free_str(str);
		print_err("Wrong color value\n");
	}
	color = 0;
	rgb_r = change_str_to_int(str[0]);
	rgb_g = change_str_to_int(str[1]);
	rgb_b = change_str_to_int(str[2]);
	color = (rgb_r << 16) + (rgb_g << 8) + rgb_b;
	free_str(str);
	return (color);
}

void	check_color(t_map *map, char *line, char c)
{
	line += 2;
	while (ft_isspace(*line))
		line++;
	if (map->f_color == -1 || map->c_color == -1)
	{
		if (c == 'F')
			map->f_color = color_parse(line);
		else if (c == 'C')
			map->c_color = color_parse(line);
	}
	else
		print_err("F and C are not seperated\n");
}
