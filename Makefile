NAME = push_swap

SRC = 	main.c \
		print.c \
		split.c \
		to_space.c \
		pile.c \
		build.c \
		ft_int.c \
		verif.c	

O = $(SRC:.c=.o)
	CC = gcc -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(O)
		$(CC) -o $@ $(O)

%.o: %.c
		$(CC) -c $<

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

tilde:
		rm -f *~

re: fclean all

.PHONY: all clean fclean re