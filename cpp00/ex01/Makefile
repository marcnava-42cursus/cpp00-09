# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 17:49:30 by marcnava          #+#    #+#              #
#    Updated: 2025/07/23 00:43:45 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex01
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS		= Contact.cpp \
			  PhoneBook.cpp \
			  main.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re