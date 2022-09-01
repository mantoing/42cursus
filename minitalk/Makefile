NAME_SERVER = server
NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRC_SERVER = minitalk_util.c server.c
SRC_CLIENT = minitalk_util.c change.c client.c

SRC_SERVER_BONUS = minitalk_util_bonus.c server_bonus.c
SRC_CLIENT_BONUS = minitalk_util_bonus.c change_bonus.c client_bonus.c

OBJ_SERVER = minitalk_util.o server.o
OBJ_CLIENT = minitalk_util.o change.o client.o

OBJ_SERVER_BONUS = minitalk_util_bonus.o server_bonus.o
OBJ_CLIENT_BONUS = minitalk_util_bonus.o change_bonus.o client_bonus.o

CC = gcc
CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME_SERVER) $(NAME_CLIENT)

bonus : $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER): $(OBJ_SERVER) minitalk.h
	$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER)
	
$(NAME_CLIENT): $(OBJ_CLIENT) minitalk.h
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT)

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS) minitalk_bonus.h
	$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER_BONUS)
	
$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS) minitalk_bonus.h
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT_BONUS)

clean:
		rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)
		rm -rf $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
		rm -rf $(OBJ_SERVER) $(OBJ_CLIENT) $(NAME_SERVER) $(NAME_CLIENT)
		rm -rf $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: server client all clean fclean re