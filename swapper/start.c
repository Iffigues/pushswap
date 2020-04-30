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

int start(t_piles *a)
{
    return free_pile(a);
}