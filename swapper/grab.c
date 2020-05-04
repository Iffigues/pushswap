#include "ft_swap.h"


void grap(t_piles *a, char *b,  void (*pf)(t_piles *)) {
    //ft_putstr(b);
    if (b) {}
    //ft_putchar('\n');
    a->count = a->count + 1;
    (pf)(a);
}