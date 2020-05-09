#include "ft_swap.h"


void ma(t_piles *a, int i) {
    int p;

    p = get_pivot(a->b);
    a->nb++;
    while (i) {
        if (a->b->i >= p) {
            grap(a,"pa",pa);
        }
        else
            grap(a,"rb", rb);
        i--;
    }
    f3(a, a->nb);
    while (a->b->nb != 1) {  
        ender(a);
    }
}

void oner(t_piles *a) {
    int i;

    i = count_list(a->b);
    if (i < 4) {
        a->nb++;
        while(a->b)
            pa(a);
    } else {
        ma(a, i);        
    }

}

int make_one(t_piles *a) {
    while (a->b) {
            oner(a);
    }
    t_pile *t = a->a->next;
    tri(a);
    while (t != a->a) {
        printf(" e = %d\n", t->i);
        t = t->next;
    }
    return 1;
}