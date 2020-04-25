#include "ft_swap.h"

int ft_compare_int(int *r, int size) {
    int i;
    int a;

    i = 0;
    while (i < size) {
        a = 0;
        while (a < size) {
            if (a != i && r[i] == r[a])
                return 0;
            a++;
        }
        i++;
    }
    return 1;
}

void ft_lstadd(t_pile **a, int b) {
    t_pile *tmp;
    t_pile *bb;

    bb = *a;
    tmp = ft_lstnew(b);
    if (*a == NULL) {
        *a = tmp;
        return;
    }
    tmp->next = bb->next;
    tmp->prev = bb;
    bb->next = tmp;
}

t_pile	*ft_lstnew(int b) {
    t_pile *a;

    if (!(a = (t_pile *)malloc(sizeof(t_pile) *  1)))
        return NULL;
    a->i = b;
    a->prev = a;
    a->next = a;
    return a;   
} 

t_piles  *new_piles(char **b) {
    t_piles *a;
    int *e;
    int i;

    i = 0;
    e = make_array_int(b);
    if (!ft_compare_int(e, count_array(b))) {
        ft_putstr(ERROR);
        return NULL;
    }
    if (!(a = (t_piles *)malloc(sizeof(t_piles) *  1))) 
        return NULL;
    a->a = NULL;
    a->b = NULL;
    //a->a = ft_lstnew(e[i++]);  
    ft_lstadd(&a->a, e[i++]);
    while (e[i])
        ft_lstadd(&a->a, e[i++]);
    free(e);
    return a;
}