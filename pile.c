#include "ft_swap.h"

t_pile *make_a(int i) {
    t_pile *a;
       
    if ((a = (t_pile *)malloc(sizeof(t_pile) *  (1))) == NULL) 
        return NULL;
    if ((a->pile = (int *)malloc(sizeof(int) *  (i * 2))) == NULL) 
        return NULL;
    a->max_size = i * 2;
    a->index = 0;
    a->size = i;
    return a;
}

void pilo(char **b, t_pile *a) {
    int i;

    i = 0;
    while (b[i]) {
        a->pile[i] = ft_atoi(b[i]);
        i++;
    }
}

t_piles  *new_piles(char **b) {
    t_piles *a;
    t_pile *aa;
    t_pile *bb;
    int i;

    i = count_array(b);
    if ((a = (t_piles *)malloc(sizeof(t_piles) *  1)) == NULL) 
        return NULL;
    aa =  make_a( i);
    pilo(b, aa);
    bb = make_a( i);
    a->a = aa; 
    a->b = bb;
    return a;
}