# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 17:35:14 by jaeywon           #+#    #+#              #
#    Updated: 2023/05/28 19:22:01 by jaeywon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind
CC = c++
CFLAGS = --std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re