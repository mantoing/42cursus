/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:05:16 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/20 19:38:25 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"

typedef struct s_map
{
	char	**map;
	int		count;
	int		check;
	char	*dir_no;
	char	*dir_so;
	char	*dir_we;
	char	*dir_ea;
}	t_map;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_info;

void	print_err(char *str);
int		ft_isspace(char c);

#endif