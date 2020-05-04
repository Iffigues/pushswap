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
                grap(a, "pb",pb);
            else
                grap(a, "ra", ra);
            i--;
        }
    }

}

int start(t_piles *a)
{

    a->count = 0;
    a->nb= 0;
    a->size= count_list(a->a);

    start_a(a);

    if (count_list(a->a) ==  2) {
        if (!is_tried(a->a)){
            if (a->b->i < a->b->next->i)
                grap(a, "ss",ss);
            else
                grap(a,"sa",sa);
        }
    }
    if (count_list(a->a) == 3) {
        step_trois(a);
    }
    go_min(a);
    start_all(a);
    printf("%d\n %d\n %d\n", a->a->i, a->count, is_tried(a->a));
    return free_pile(a);
}