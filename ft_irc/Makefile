NAME = ircserv

CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98

SRC = main.cpp \
	  server.cpp \
	  channel.cpp \
	  client.cpp \
	  cmd.cpp \
	  pass.cpp \
	  nick.cpp \
	  user.cpp \
	  util.cpp \
	  privmsg.cpp \
	  ping.cpp \
	  topic.cpp \
	  join.cpp \
	  quit.cpp \
	  kick.cpp \
	  mode.cpp \
	  part.cpp \
	  invite.cpp \
	  who.cpp \
	  whois.cpp


OBJ = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
