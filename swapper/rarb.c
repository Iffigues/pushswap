#include "ft_swap.h"

void ra(t_piles *a) {
    a->a = a->a->next;
}

void rb(t_piles *a) {
    a->b = a->b->next;
}

void rr(t_piles *a) {
    ra(a);
    rb(a);
}