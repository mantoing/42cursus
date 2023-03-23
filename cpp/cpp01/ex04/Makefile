# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 15:43:04 by jaeywon           #+#    #+#              #
#    Updated: 2023/03/23 18:35:21 by jaeywon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Sed
CC = c++
CFLAGS = --std=c++98 -Wall -Wextra -Werror
SRCS =  main.cpp sed.cpp
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