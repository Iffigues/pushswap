#include "ft_swap.h"

void free_array(char **b) {
    int i;

    i = 0;
    while (b[i])
        free(b[i++]);
    free(b);
}

void ft_count_list(t_pile *a) {
    t_pile *tmp;
    t_pile *aa;
    t_pile *f;

    if (!a) {
        return;
    }
    tmp = a;
    aa = a->next;
    while (aa != tmp) {
        f = aa;
        aa = aa->next;
        free(f);
    }
    free(tmp);
}

void free_pile(t_piles *a) {
    ft_count_list(a->a);
    ft_count_list(a->b);
    free(a);
}