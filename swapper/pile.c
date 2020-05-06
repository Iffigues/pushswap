#include "ft_swap.h"

int ft_compare_int(int *r, int size)
{
    int i;
    int a;

    i = 0;
    while (i < size)
    {
        a = 0;
        while (a < size)
        {
            if (a != i && r[i] == r[a])
                return 0;
            a++;
        }
        i++;
    }
    return 1;
}

void ft_lstadd(t_pile **a, int b, int c)
{
    t_pile *tmp;
    t_pile *bb;

    bb = *a;
    tmp = ft_lstnew(b, c);
    if (*a == NULL)
    {
        *a = tmp;
        return;
    }
    tmp->next = bb;
    tmp->prev = bb->prev;
    bb->prev->next = tmp;
    bb->prev = tmp;
}

t_pile	*ft_lstnew(int b, int t)
{
    t_pile *a;

    if (!(a = (t_pile *)malloc(sizeof(t_pile) *  1)))
        return NULL;
    a->i = b;
    a->i = 0;
    a->nb = t;
    a->prev = a;
    a->next = a;
    return a;   
} 

void *free_both(char **b, int *a)
{
    free(a);
    free_array(b);
    return NULL;
}


t_piles  *new_piles(char **b)
{
    t_piles *a;
    int *e;
    int i;
    int size;

    size = count_array(b);
    i = 0;
    e = make_array_int(b);
    if (!ft_compare_int(e, count_array(b)))
        return free_both(b, e);
    if (!(a = (t_piles *)malloc(sizeof(t_piles) *  1))) 
        return NULL;
    a->a = NULL;
    a->b = NULL;
    a->nb = 0;

    while (i < size)
        ft_lstadd(&a->a, e[i++], a->nb);
    free_both(b, e);
    return a;
}