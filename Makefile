# Makefile

NAME = sokoban

SRCS = main.c \
	functions/board.c \
	functions/box.c \
	functions/character.c \
	functions/goal.c

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all