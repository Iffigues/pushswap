#include "ft_swap.h"

int get_max(t_pile *a) {
    int i;
    t_pile *tmp;

    if (a) {
        i = a->i;
        tmp = a->next;
        while (tmp != a) {
            if (tmp->i > i) {
                i = tmp->i;
            }
            tmp = tmp->next;
        }
    }
    return i;
} 

int get_min(t_pile *a) {
    int i;
    t_pile *tmp;

    if (a) {
        i = a->i;
        tmp = a->next;
        while (tmp != a) {
            if (tmp->i < i) {
                i = tmp->i;
            }
            tmp = tmp->next;
        }
    }
    return i;
}

int start(t_piles *a) {
    return free_pile(a);
}