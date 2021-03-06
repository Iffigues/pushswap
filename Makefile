NAME = push_swap

SRC =	./main.c \
	./swapper/grab.c \
	./swapper/one.c \
	./swapper/fixed.c \
	./swapper/maker.c \
	./swapper/step.c \
	./swapper/rarb.c \
	./swapper/rrarrb.c \
	./swapper/start.c \
	./swapper/print.c \
	./swapper/error.c \
	./swapper/split.c \
	./swapper/to_space.c \
	./swapper/pile.c \
	./swapper/finish.c \
	./swapper/free.c \
	./swapper/sasb.c \
	./swapper/papb.c \
	./swapper/build.c \
	./swapper/ft_int.c \
	./swapper/verif.c	

O = $(SRC:.c=.o)
	CC = gcc -Wall -Wextra -Werror 

$(NAME): $(O)
	$(CC) -o $@ *.o

%.o: %.c
	$(CC) -c $<

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

tilde:
	rm -f *~

re: fclean all

.PHONY: all clean fclean re
