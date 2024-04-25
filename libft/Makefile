NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar
ARFLAGS = rcs
SRCS = $(filter-out %_bonus.c,$(wildcard *.c))
BONUS_SRCS = $(wildcard *_bonus.c)
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
DEPS = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
