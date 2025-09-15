# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 13:50:02 by marcnava          #+#    #+#              #
#    Updated: 2025/08/26 13:50:02 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
