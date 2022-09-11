NAME = push_swap
CC = cc
CFLAGS = -fsanitize=address
SRC = prt_error.c push_swap.c stack.c init.c parse.c \
		ft_atoi_push.c
OBJ = $(SRC:.c=.o)
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) -o $@ $^ -L./libft -lft

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c $^
	
clean:
	$(RM) WITH_B=1 $(OBJ)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re:	fclean all