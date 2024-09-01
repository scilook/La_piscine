CC=cc
CFLAGS=-Wall -Wextra -Werror
CS=main.c
OBJS=$(CS:.c=.o)
TARGET=do-op

%.o: $(CS)
	$(CC) -c $(CFLAGS) $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

all: $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re