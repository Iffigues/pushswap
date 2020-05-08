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
    while (a->b->prev->nb != 1) 
        grap(a, "rrb", rrb);
    //printf("%d\n",a->b->nb);
}

int getg(t_pile *a) {
    t_pile *tmp;
    int i;
    int y;

    i = a->nb;
    y = a->i;
    tmp = a;
    while (tmp->prev->nb == i) {
    tmp = tmp->prev;
    //printf("eeeoooood=%d\n",tmp->i);
    }
    while (tmp->nb == i) {
       // printf("eeeoooood=%d",tmp->i);
        if (y > tmp->i)
            y = tmp->i;
        tmp = tmp->next;
    }
    return y;
}

//void go_maxi(t_piles *a) {
   // while (a->b->->nb != 1)
     //   grap(a, "rb", rb);
//}

int count_nb(t_pile *a, int t) {
    t_pile *tmp;
    int i;

    i = 0;
 
    tmp = a;
    while (tmp->prev->nb == t)
        tmp = tmp->prev;
    while (tmp->nb == t) {
        i++;
        tmp = tmp->next;
    }
    return i;
}


int *make_intel(t_pile *a, int t) {
    int *i;
    int c;

    c = 0;
    i = (int *)malloc(sizeof(int) * t);
    while (c < t) {
         
            i[c++] = a->i;
 
            a = a->next;
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
    t_pile *tmp;
    int *i;
    int hh;
    int c;
    int v;

    c = 0;
    tmp = a;
    hh = 0;
    while (tmp->prev->nb == t) 
        tmp = tmp->prev;
    v = count_nb(tmp,t);
    i = make_intel(tmp, v);
        while  (c < v) {
        if (is_g(i, i[c], v)){
            hh = i[c];
            free(i);
            return hh;
        }
        c++;
    }
 
    free(i);
    return hh;
}

int have_rev_pivot(t_pile *a, int y, int i) {
    t_pile *tmp;
    int yy = count_nb(a, i);

    tmp = a;
    while (tmp->prev->nb == i)
        tmp = tmp->prev;
     while (yy--) {
        if (tmp->i <= y) {
            return 1;
        }
        tmp =  tmp->next;
    }
    return 0;
}

void f3(t_piles *a, int i) {
    int p;
    p = 0;

    p = get_b_pivot(a->a, i);   
    a->nb++;
    while (count_nb(a->a, i) > 2) {
            if (!have_rev_pivot(a->a, p, i)){
                p = get_b_pivot(a->a, i);   
                a->nb++; 
            }
            if (a->a->i <=  p) 
                grap(a, "pb", pb);
            else if (get_sens(a->a, p, i)) {
                grap(a, "ra", ra);
            } else {
                grap(a,"rra", rra);
            }
    } 
    while (a->a->prev->fixe != 1 )
        grap(a,"rra", rra);

}

int get_sens(t_pile *a, int p, int i) {
    t_pile *tmp;

    tmp = a;
    printf("merdouille\n");
    if (tmp->nb  != i) {
        if (a->next->nb == i)
            return 1;
        else
            return 0;
    }
    printf("merdasse\n");
    while (tmp->nb == i) {
        if (tmp->i <= p)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

int is_b_tried(t_pile *a, int i) {
    t_pile *tmp;

    tmp = a->next;
    while (tmp->nb == i) {
        if (tmp->prev->i < tmp->i)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}

int ender(t_piles *a) {
    int b;
    int p;

    a->nb++;
    b = a->b->nb;
    p = get_b_pivot(a->b, b);
    //("%d\n", count_nb(a->b, a->b->nb));
    if (count_nb(a->b, a->b->nb) > 3) {
        while (count_nb(a->b, b) > 2 && have_pivot(a->b, p)){
            if (a->b->i >=  p) 
                grap(a, "pa", pa);
            else 
                grap(a, "rb", rb);     
        }
        go_max(a);
        //printf("prev = %d\n", a->b->prev->nb );
        f3(a, a->nb);
    } else {
         go_max(a);
            grap(a, "pa", pa);
    }
    return 1;
}

void tri(t_piles *a) {
    while (a->a->fixe == 0) {
        if (a->a->i > a->a->next->i)
            grap(a, "sa", sa);
        else
        grap(a, "ra", ra);
        ///printf("%d\n", a->a->i);
    }
    if (a->a->fixe == 1)
    grap(a, "rra", rra);
    while (a->a->fixe == 0) {
    
        if (a->a->i > a->a->next->i)
            grap(a, "sa", sa);
        else
        grap(a, "rra", rra);
           //     printf("%d\n", a->a->i);
        
    }
    grap(a, "ra", ra);
}

int start_all (t_piles *a) {
    fixed(a->a);
   
    while (a->b) {
        if (a->b->nb == 1) {
           // printf("%d %d\n", a->a->prev->fixe, a->a->fixe);
            tri(a);
           
        t_pile *tms = a->a->next;
            while (tms != a->a) {
                   //printf("%d %d %d\n", tms->i, tms->nb, tms->nb);
                    tms = tms->next;
            }
            printf("%d tired = %d\n", a->count, is_tried(a->a));
            exit(0);
        } else {
            //printf("aa\n");
            ender(a);
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
    return 1;
}