#include "ft_swap.h"

int count_div(t_pile *a) {
    int aa;
    int b;
    t_pile *tmp;

    b = 0;
    aa = 0;
    if (!(count_list(a) & 1)) 
        b++;
    tmp = a->next;
    while (tmp != a) {
        if (tmp->i < a->i)
            aa++;
        if (tmp->i > a->i)
            b++;
        tmp = tmp->next;
    }
    
    return aa == b;
}

int get_pivot(t_pile *a) {
    t_pile *tmp;
    tmp = a;

    tmp = tmp->next;
    if (count_list(a) > 2) 
        while (tmp != a) {
            if (count_div(tmp))
                return tmp->i;
            tmp = tmp->next;
     }
    return 0;
}

int is_tried(t_pile *a) {
    t_pile *tmp;
    t_pile *tmps;
    int i;

    i = get_min(a);
    tmp = a;
    while (tmp->i != i){
        tmp = tmp->next;
    }
    tmps = tmp->next;
    while (tmps != tmp) {
        if (tmps->i < i)
            return 0;
        i = tmps->i;
        tmps = tmps->next;
    }
    return 1;
}