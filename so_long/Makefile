NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c map.c print_error.c \
		get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
RM = /bin/rm -f

all: $(NAME)

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c $^

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L./mlx -lmlx -framework OpenGL -framework AppKit

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all