# include "ft_swap.h"

void step_trois(t_piles *a) {

    while (!is_tried(a->a)) {
        if (a->a->i > a->a->next->i && a->b->i < a->b->next->i) {
            ss(a);
        }
        else if (a->a->i > a->a->next->i) {
            sa(a);
        }
        else {
            ra(a);
        }
    }
}

void go_min(t_piles *a) {
    t_pile *tmp;
    int y;
    int u;

    y = 0;
    u = 0;
    tmp = a->a;
    while (get_min(a->a) != tmp->i) {
        y++;
        tmp = tmp->next;
    }
     tmp = a->a;
    while (get_min(a->a) != tmp->i) {
        u++;
        tmp = tmp->prev;
    }
    while (get_min(a->a) != a->a->i)
    {
        if (y >= u)
            rra(a);
        else
            ra(a);
    }
}