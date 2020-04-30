#include "ft_swap.h"


int is_tried(t_pile *a) {
    t_pile *tmp;
    int i;

    tmp = a;
    i = a->i;
    while (tmp->next != a) {
        if (tmp->i < i)
            return 0;
        i = tmp->i;
        tmp = tmp->next;
    }
    return 1;
}