# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 18:32:39 by hyeson            #+#    #+#              #
#    Updated: 2024/08/30 16:00:22 by hyeson           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
AR=ar
CFLAGS=-c -Wall -Wextra -Werror
ARFLAGS=-r
CS=$(wildcard ./srcs/*.c)
OBJS=$(CS:.c=.o)
INCLUDES=./includes/ft.h
TARGET=libft.a

%.o: %.c $(INCLUDES)
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