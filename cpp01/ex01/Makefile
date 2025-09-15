# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 13:49:07 by marcnava          #+#    #+#              #
#    Updated: 2025/08/26 13:49:08 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= horde
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

BUILDPATH	= build

SRCS		=	main.cpp \
				Zombie.cpp \
				zombieHorde.cpp

OBJS		= $(SRCS:%.cpp=$(BUILDPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BUILDPATH)/%.o: %.cpp
	@mkdir -p $(BUILDPATH)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDPATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
