# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 18:45:08 by jaeywon           #+#    #+#              #
#    Updated: 2023/02/23 22:02:51 by jaeywon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = ./libft
SRC = main.c check_color.c check_dir.c ft_parse.c utils.c init.c check_wall.c \
		load_map.c
OBJ = $(SRC:.c=.o)
NAME = cub3D
MLXDIR = ./mlx

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
		$(MAKE) all -C $(LIBDIR)
		$(MAKE) -C $(MLXDIR)
		$(CC) -o $(NAME) $(OBJ) -L $(LIBDIR) -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

clean :
		$(MAKE) -C $(LIBDIR) clean
		$(MAKE) -C $(MLXDIR) clean
		rm -f $(OBJ)

fclean : clean
		$(MAKE) -C $(LIBDIR) fclean
		rm -f $(NAME)

re :
		make fclean
		make all

.PHONY: all clean fclean re