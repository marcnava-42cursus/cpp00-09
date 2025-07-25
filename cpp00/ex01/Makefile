NAME		= phonebook
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -Iincludes

BUILDPATH	= build
SRCSPATH	= src

SRCS		= $(SRCSPATH)/Contact.cpp \
			  $(SRCSPATH)/PhoneBook.cpp \
			  $(SRCSPATH)/main.cpp

OBJS		= $(SRCS:$(SRCSPATH)/%.cpp=$(BUILDPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Regla de compilación
$(BUILDPATH)/%.o: $(SRCSPATH)/%.cpp
	@mkdir -p $(BUILDPATH)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDPATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
