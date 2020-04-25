# include "ft_swap.h"

int main (int argc, char **argv) {
	char **e;
	if (argc == 1) {
		return 0;
	}
	e = split(argv[1]);
	if (!verif_int(e)) {
		ft_putstr(ERROR);
		return 0;
	}
	new_piles(e);
}
