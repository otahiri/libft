CC = cc
NAME = libft.a

all: $(NAME)

FLAGS = -Wextra -Werror -Wall -I.

SRCS = ft_strlen.c

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $@ $^

.phony: all clean fclean re
