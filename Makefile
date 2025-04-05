NAME = libgnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

BUFFER_SIZE = 42

HEADER = get_next_line.h

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -D BUFFER_SIZE -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re