NAME		= form
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

BUILDPATH	= build

SRCS		= src/main.cpp \
			  src/Bureaucrat.cpp \
			  src/Form.cpp

OBJS		= $(SRCS:%.cpp=$(BUILDPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -Iincludes -o $(NAME) $(OBJS)

$(BUILDPATH)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	rm -rf $(BUILDPATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
