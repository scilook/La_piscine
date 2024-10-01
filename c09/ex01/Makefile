# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 18:32:39 by hyeson            #+#    #+#              #
#    Updated: 2024/08/31 12:32:10 by hyeson           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
AR=ar
CFLAGS=-c -Wall -Wextra -Werror
ARFLAGS=rcs
CS=./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS=$(CS:.c=.o)
INCLUDES=./includes/ft.h
TARGET=libft.a

%.o: $(CS) $(INCLUDES)
	$(CC) $(CFLAGS) $< -o $@

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

all: $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re