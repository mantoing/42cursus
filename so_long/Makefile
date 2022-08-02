NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c map.c print_error.c utils.c \
		get_next_line.c get_next_line_utils.c \
		images.c elements.c move.c
OBJ = $(SRC:.c=.o)
RM = rm -f

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