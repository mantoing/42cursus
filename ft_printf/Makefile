NAME 		= libftprintf.a

SRCS 		= ft_printf.c \
			  functions.c \
			  par_arg.c \
			  print_format_type.c \
			  prtchar.c \
			  prtnbr.c \
			  prtstr.c 

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rc
RM			= rm -f

$(NAME)	: $(OBJS)
	$(AR) $(NAME) $(OBJS)

.PHONY	: all
all : $(NAME)

.PHONY	: clean
clean	:
	$(RM) $(OBJS)

.PHONY	: fclean
fclean	: clean
	$(RM) $(NAME)

.PHONY	: re
re		: fclean all