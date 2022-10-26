# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 15:51:28 by jaeywon           #+#    #+#              #
#    Updated: 2022/10/26 15:54:38 by jaeywon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = CC
CFLAGS = -fsanitize=thread -g3
# CFLEAG = -Wall -Wextra -Werror
SRC = main.c init.c philo.c prt_error.c thread.c util.c
OBJ = $(SRC:.c=.o)
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c $^
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all