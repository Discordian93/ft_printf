NAME = libftprintf.a
LIBFT = libft/libft.a
LIBFT_DIR = libft/

SRCS = *.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L. -lft

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	echo "create $(NAME)\naddlib $(NAME)\naddlib $(LIBFT)\nsave\nend" | ar -M

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
