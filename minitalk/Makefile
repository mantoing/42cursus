NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = minitalk_util.c server.c
SRC_CLIENT = minitalk_util.c change.c client.c

OBJ_SERVER = minitalk_util.o server.o
OBJ_CLIENT = minitalk_util.o change.o client.o

CC = gcc
CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) minitalk.h
	$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER)
	
$(NAME_CLIENT): $(OBJ_CLIENT) minitalk.h
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT)


clean:
		rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
		rm -rf $(OBJ_SERVER) $(OBJ_CLIENT) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: server client all clean fclean re