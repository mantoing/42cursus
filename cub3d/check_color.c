/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:18:28 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/27 04:31:10 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	free_str(char **str)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 		free(str[i]);
// 	free(str);
// }

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
		print_err("split error\n" );
	if (str[0] == NULL || str[1] == NULL || str[2] == NULL)
		print_err("COLOR imformations split dailed\n");
	color = 0;
	str[2][ft_strlen(str[2]) - 1] = '\0';
	rgb_r = change_str_to_int(str[0]);
	rgb_g = change_str_to_int(str[1]);
	rgb_b = change_str_to_int(str[2]);
	printf("r = %d\n", rgb_r);
	printf("g = %d\n", rgb_g);
	printf("b = %d\n", rgb_b);
	color = (rgb_r << 16) + (rgb_g << 8) + rgb_b;
	printf("color = %d\n", color);
	// free_str(str);
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
	{
		printf("fcolor = %d\n", map->f_color);
		printf("ccolor = %d\n", map->c_color);
		print_err("F and C are not seperated\n");
	}
	// free(line);
}
