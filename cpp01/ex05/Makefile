# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 13:48:44 by marcnava          #+#    #+#              #
#    Updated: 2025/10/28 18:10:12 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= harl
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

BUILDPATH	= build

SRCS		= main.cpp \
			  Harl.cpp

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
