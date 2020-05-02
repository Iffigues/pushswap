#include "ft_swap.h"

int get_max(t_pile *a)
{
    int i;
    t_pile *tmp;

    i = 0;
    if (a)
    {
        i = a->i;
        tmp = a->next;
        while (tmp != a)
        {
            if (tmp->i > i)
            {
                i = tmp->i;
            }
            tmp = tmp->next;
        }
    }
    return i;
}

int get_min(t_pile *a)
{
    int i;
    t_pile *tmp;

    i = 0;
    if (a)
    {
        i = a->i;
        tmp = a->next;
        while (tmp != a)
        {
            if (tmp->i < i)
            {
                i = tmp->i;
            }
            tmp = tmp->next;
        }
    }
    return i;
}

int count_list(t_pile *a)
{
    t_pile *tmp;
    int i;

    if (!a)
        return 0;
    i = 1;
    tmp = a;
    while (tmp->next != a)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}

void start_a(t_piles *a) {
    int p;
    int i;

    i = count_list(a->a);
    while((i = count_list(a->a)) > 3) {
        if (is_tried(a->a))
            return;
        a->nb++;
        p = get_pivot(a->a);

        while(i > 0) {
            if (a->a->i < p)
                pb(a);
            else
                ra(a);
            i--;
        }
    }

}

int start(t_piles *a)
{
    start_a(a);
    printf("%d\n",a->b->i);
    if (count_list(a->a) ==  2) {
        if (!is_tried(a->a)){
            if (a->b->i < a->b->next->i)
                ss(a);
            else
                sa(a);
        }
    }
    if (count_list(a->a) == 3) {
        step_trois(a);
    }
    go_min(a);
    while (a->b) {
        printf("%d\n",a->b->i);
        break;
        a->b = a->b->next;
    }
    return free_pile(a);
}