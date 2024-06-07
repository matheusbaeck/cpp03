# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: math <math@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 18:22:45 by math42            #+#    #+#              #
#    Updated: 2024/06/06 13:16:08 by math             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Folders and Names
NAME		= ex
SRCSDIR		= .
INCLUDES	= .

SRCS		= main.cpp ClapTrap.cpp ClapTrap.cpp  ScavTrap.cpp

# Compiler options
CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCSDIR)/$(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re test

