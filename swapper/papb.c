#include "ft_swap.h"

int is_one(t_pile *s) {
    if (s->next == s) {
        return 1;
    }
    return 0;
}

void pb(t_piles *a) {
    int i;
    t_pile *e;
    int y;

    if (a->a != NULL) 
    {
        y = is_one(a->a);
        i = a->a->i;
        e = a->a;
        a->a = a->a->next;
        a->a->prev->prev->next =  a->a;
        a->a->prev =  a->a->prev->prev;
        free(e);
        ft_lstadd(&a->b,i, a->nb);
        a->b = a->b->prev;
        if (y) 
            a->a = NULL;
    }
}

void pa(t_piles *a) {
    int i;
    t_pile *e;
    int y;


    if (a->b != NULL) 
    {
        y = is_one(a->b);
        i = a->b->i;
        e = a->b;
        a->b = a->b->next;
        a->b->prev->prev->next =  a->b;
        a->b->prev =  a->b->prev->prev;
        free(e);
        ft_lstadd(&a->a,i, a->nb);
        a->a = a->a->prev;
        if (y) 
            a->b = NULL;
    }
}