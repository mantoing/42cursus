# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 15:24:20 by kwpark            #+#    #+#              #
#    Updated: 2023/03/07 20:05:33 by kwpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = cub3D

NAMEB = cub3D_bonus

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

MLX = minilibx

SOURCES = 	mandatory/src/check_color.c \
			mandatory/src/check_dir.c \
			mandatory/src/check_wall.c \
			mandatory/src/cub3d_utils.c \
			mandatory/src/cub3d.c \
			mandatory/src/ft_parse.c \
			mandatory/src/init.c \
			mandatory/src/key_update.c \
			mandatory/src/load_map.c \
			mandatory/src/raycasting_utils.c \
			mandatory/src/raycasting.c \
			mandatory/src/ft_parse_utils.c \
			mandatory/src/utils.c

BONUS = 	bonus/src/check_color_bonus.c \
			bonus/src/check_dir_bonus.c \
			bonus/src/check_wall_bonus.c \
			bonus/src/cub3d_utils_bonus.c \
			bonus/src/cub3d_bonus.c \
			bonus/src/ft_parse_bonus.c \
			bonus/src/init_bonus.c \
			bonus/src/key_update_bonus.c \
			bonus/src/load_map_bonus.c \
			bonus/src/raycasting_utils_bonus.c \
			bonus/src/raycasting_bonus.c \
			bonus/src/ft_parse_utils_bonus.c \
			bonus/src/utils_bonus.c

OBJS = $(SOURCES:.c=.o)
OBJB = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(MLX)
	@cp libft/libft.a ./
	@cp minilibx/libmlx.a ./
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) libft.a libmlx.a

bonus: $(NAMEB)

$(NAMEB): $(OBJB)
	@make -C $(LIBFT)
	@make -C $(MLX)
	@cp libft/libft.a ./
	@cp minilibx/libmlx.a ./
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAMEB) $(OBJB) libft.a libmlx.a


%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS) libft.a libmlx.a
	@make clean -C $(LIBFT)
	@rm -f $(OBJB)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAMEB)
	@make fclean -C $(LIBFT)
	@make clean -C $(MLX)

re: fclean all

.PHONY : all, clean, fclean, re, bonus