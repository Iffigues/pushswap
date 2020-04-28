# include "./swapper/ft_swap.h"

int main (int argc, char **argv) {
	char **e;
	t_piles *p;

	if (argc == 1) {
		return 0;
	}
	e = split(argv[1]);
	if (!verif_int(e))
		return errors();
	p =	new_piles(e);
	if (!p)
		return errors();
	return start(p);
}
