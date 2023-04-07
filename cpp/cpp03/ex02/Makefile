# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 22:01:23 by jaeywon           #+#    #+#              #
#    Updated: 2023/04/08 04:46:09 by jaeywon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap
CC = c++
CFLAGS = --std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
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