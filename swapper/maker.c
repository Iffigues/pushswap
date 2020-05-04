#include "ft_swap.h"



void go_go(t_piles *a, char b, int c) {

     if (b == 'b')
        while (a->b->prev->nb == c)
            grap(a,"rrb", rr);
      if (b == 'a')
        while (a->a->prev->nb == c)
            grap(a,"rrb", rr);
}

void go_max(t_piles *a) {
    t_pile *tmp;
    int y;
    int u;

    y = 0;
    u = 0;
    tmp = a->b;
    while (get_max(a->b) != tmp->i) {
        y++;
        tmp = tmp->next;
    }
    tmp = a->b;
    while (get_max(a->b) != tmp->i) {
        u++;
        tmp = tmp->prev;
    }
    while (get_max(a->b) != a->b->i)
    {
        if (y >= u)
            grap(a, "rrb",rrb);
        else
            grap(a, "rb", rb);
    }
}



int count_nb(t_pile *a, int t) {
    t_pile *tmp;
    int i;

    i = 0;
 
    tmp = a;
    while (tmp->prev->nb == t && tmp->prev != a)
        tmp = tmp->prev;
    while (tmp->nb == t && tmp->next != a) {
        i++;
        tmp = tmp->next;
    }

    return i;
}


int *make_intel(t_pile *a, int t, int r) {
    int *i;
    t_pile *tmp;
    int c;

    c = 0;
    tmp = a;
    i = (int *)malloc(sizeof(int) * t);
    while(tmp->prev->nb == r && tmp != a )
    {
            tmp = tmp->prev;
    }
    while (c < t) {
            i[c++] = tmp->i;
            tmp = tmp->prev;
    }
    return i;
}

int is_g(int *i, int y, int s) {

    int aa;
    int b;
    int g;

    aa = 0;
    b = 0;
    g = 0;
     if (!(s & 1)) 
        b++;
    while (g < s) {
        if (i[g] < y)
            aa++;
        if (i[g] > y)
            b++;
        g++;
    }
    return aa == b;
}

int have_pivot(t_pile *a, int y) {
    t_pile *tmp;

    tmp = a->next;
    if (a->i >= y) {
        return 1;
    }
    while (tmp != a) {
        if (tmp->i >= y)
            return 1;
            tmp =  tmp->next;
    }
    return 0;
}

int min_pivot(t_pile *a, int y) {
    t_pile *tmp;

    tmp = a->next;
    if (a->i <= y) {
        return 1;
    }
    while (tmp != a) {
        if (tmp->i <= y)
            return 1;
            tmp =  tmp->next;
    }
    return 0;
}

int get_b_pivot(t_pile *a, int t) {
    int c;
    int *i;
    int hh;

    hh = 0;
    c = 0;
    i = make_intel(a,count_nb(a, t), t);
    while  (c < count_nb(a, t)) {
        if (is_g(i, i[c], count_nb(a, t))){
            hh = i[c];
            free(i);
            return hh;
        }
        c++;
    }
 
    free(i);
    return hh;
}

void f3(t_piles *a, int i) {
    int p;
    int sens;
    
    i = a->a->nb;
    p = get_b_pivot(a->a, i);    
    a->nb++;
    while (count_nb(a->a, i) > 2) {
       if (!min_pivot(a->a, p)) {
            p = get_b_pivot(a->a, i);
            a->nb++;
       }
       sens = get_sens(a->a, p, i);
        if (a->a->i <  p)
            grap(a, "pb", pb);
        else if (sens)
             grap(a, "rra", rra);
        else if (!sens)
            grap(a, "ra", ra);
    } 
    go_min(a);
}

int get_sens(t_pile *a, int p, int i) {
    t_pile *tmp;

    tmp = a;
    while (tmp->nb == i) {
        if (tmp->i >= p)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

int ender(t_piles *a) {
    int i;
    int b;
    int p;
    int sens;

    sens = 0;
    b = a->b->nb;
    i = a->a->nb;
    p = get_b_pivot(a->b, b); 
    while (count_nb(a->b, b) > 1) {
        if (!have_pivot(a->b, p))
            p = get_b_pivot(a->b, b);
        sens = get_sens(a->b, p, b);
        if (a->b->i >=  p)
            grap(a, "pa", pa);
        else if (sens)
             grap(a, "rb", rrb);
        else if (!sens) {
            grap(a, "rrb", rb);
        }
            
    }
    go_max(a);
    f3(a, b);
    return 1;
}

int start_all (t_piles *a) {
    int i;
    
    while ((i = count_list(a->b))) {
        if (count_nb(a->b, a->b->nb) > 3)
            ender(a);
        else {
            go_max(a);
            grap(a, "pa", pa);
        }
    }
    return 1;
}

int make_end(t_piles *a) {
    if (count_list(a->b) == 2)
        while (a->b) {
            if (a->b->i == get_max(a->b))
                grap(a, "pa",pa);
            else
                grap(a,"rb", rb);
        }
    if (count_list(a->b) == 3) 
        while (a->b) {
            if (a->b->prev->i == get_max(a->b))
                grap(a, "rrb", rrb);
            if (a->b->next->i == get_max(a->b))
                grap(a, "rb", rb);
            grap(a, "pa", pa);
        }
         grap(a, "pa", pa);
    printf("sz = %d\n", count_list(a->a));
    return 1;
}