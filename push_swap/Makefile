NAME = push_swap
CC = cc
CFLAGS = -fsanitize=address -g3
SRC = prt_error.c push_swap.c stack.c init.c parse.c \
		push.c swap.c rotate.c reverse_rotate.c prepare_sort.c \
			sort_a.c hard_sort.c sort_b.c only_sort.c is_sorted.c
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