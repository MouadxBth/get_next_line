NAME	= driver

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra -g -D BUFFER_SIZE=1024

SRCS	= get_next_line.c get_next_line_utils.c main.c

INC	= get_next_line.h

all: $(NAME)

$(NAME): $(SRCS) $(INC)
	$(CC) $(CFLAGS) $(SRCS) -include $(INC) -o $@

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re
