# include "ft_swap.h"

int main (int argc, char **argv) {
	char **e;
	t_piles *p;

	if (argc == 1) {
		return 0;
	}
	e = split(argv[1]);
	if (!verif_int(e)) {
		ft_putstr(ERROR);
		return 0;
	}
	p =	new_piles(e);
	pb(p);
	pb(p);
	pb(p);
	pb(p);
	pb(p);
	if (p == NULL) {
		return 0;
	}
	free_pile(p);
}
