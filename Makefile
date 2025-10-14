CC = cc
NAME = libft.a

all: $(NAME)

FLAGS = -Wextra -Werror -Wall -I

SRCS = ft_strlen.c

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

.phony: all clean fclean re
