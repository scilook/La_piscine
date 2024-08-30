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
LDLIBS=./includes/ft.h
OBJS=$(wildcard ./srcs/*.o)
CS=$(wildcard ./srcs/*.c)
TARGET=libft.a

%.o: $(CS)
	$(CC) $(CFLAGS) $(LDLIBS) $< -o $@ (CS)

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

all: $(TARGET)

clean: rm -f %.o

fclean:
	rm -f %.o
	rm -f $(TARGET)

re:
	fclean
	all

.PHONY: all clean fclean re