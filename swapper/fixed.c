#include "ft_swap.h"

void fixed(t_pile *a) {
    t_pile *tmp;

    tmp = a->next;
    a->fixe = 1; 
    while (tmp != a) {
        tmp->fixe = 1;
        tmp = tmp->next;
    }
}

void rfixed(t_pile *a) {
    t_pile *tmp;

    tmp = a->next;
    a->y = 1; 
    while (tmp != a) {
        tmp->y = 1;
        tmp = tmp->next;
    }
}