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

int count_list(t_pile *a) {
    t_pile *tmp;
    int i;

    if (!a)
        return 0;
    i = 1;
    tmp = a;
    while (tmp->next != a) {
        i++;
        tmp = tmp->next;
    }
    return i;
}

float moyenne(t_pile *a, float min, float max) {
    float middle;
    t_pile *tmp;
    int i;

    i = count_list(a);
    tmp = a;
    middle = ((float)a->i - min)/(min - max);
    tmp = tmp->next;
    while (tmp != a) {
        middle = middle + (((float)tmp->i - min)/(min - max));
    }
    return middle / (float)i;
}

float get_moyenne(t_pile *a) {
    float min;
    float max;

    min = get_min(a);
    max = get_max(a);
    return moyenne(a, min, max);
}

int start(t_piles *a) {
    return free_pile(a);
}