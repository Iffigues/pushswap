#include "ft_swap.h"

void rra(t_piles *a) {
    a->a = a->a->prev;
}

void rrb(t_piles *a) {
    a->b = a->b->prev;
}

void rrr(t_piles *a) {
    rra(a);
    rrb(a);
}

