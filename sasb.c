#include "ft_swap.h"


void sa(t_piles *a) {
    int b;


    if (a->a == a->a->next) {
        return;
    }
    b = a->a->i;
    a->a->i = a->a->next->i;
    a->a->next->i = b;
}

void sb(t_piles *a) {
    int b;


    if (a->b == a->b->next) {
        return;
    }
    b = a->b->i;
    a->b->i = a->b->next->i;
    a->b->next->i = b;
}

void ss(t_piles *a) {
    sa(a);
    sb(a);
}

