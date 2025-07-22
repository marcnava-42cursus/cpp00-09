# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarcell <jmarcell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 17:49:30 by jmarcell          #+#    #+#              #
#    Updated: 2025/07/22 18:51:41 by jmarcell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex01
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS		= Contact.cpp \
			  PhoneBook.cpp

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