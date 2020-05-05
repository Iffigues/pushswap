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
    printf("eeeoooood=%d\n",tmp->i);
    }
    while (tmp->nb == i) {
        printf("eeeoooood=%d",tmp->i);
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

    tmp = a->next;
     printf("pivot = %d\n", y);
    if (a->i <= y) {
        printf("eeeoooood=%d",tmp->i);

        return 1;
    }
    printf("pivot = %d\n", y);
    while (tmp->prev->nb == i)
        tmp = tmp->prev;
     while (tmp->nb == i) {
        if (tmp->i <= y) {
            printf("eeed=%d",tmp->i);
            return 1;
        }
        tmp =  tmp->next;
    }
    printf("ddf = %d\n",a->nb);
    return 0;
}

void f3(t_piles *a, int i) {
    int p;
    p = 0;

    if (is_tried(a->a)) 
        return;
    p = get_b_pivot(a->a, i);   
    a->nb++;
    while (count_nb(a->a, i) > 2) {
            printf("count = %d\n", is_tried(a->a));
            if (!have_rev_pivot(a->a, p, i)){
                p = get_b_pivot(a->a, i);   
                a->nb++; 
            }
            if (a->a->i <=  p) {
                grap(a, "pb", pb);
            if (a->a->nb != i)
                    grap(a,"rra", rra);
            } else if (get_sens(a->a, p, i)) {
                grap(a, "ra", ra);
            }
    } 
    while (a->a->prev->i != get_max(a->a))
        grap(a,"rra", rra);
    if (a->a->next->i > a->a->i)
        grap(a, "sa", sa);
        printf("is s %d  %d %d %d %d %d\n",count_nb(a->a, i), a->a->prev->nb, a->a->nb, a->a->next->nb, a->a->next->nb, a->a->next->next->nb);

}

int get_sens(t_pile *a, int p, int i) {
    t_pile *tmp;

    tmp = a;
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
     
    b = a->b->nb;
   p = get_b_pivot(a->b, b);
    printf("aaa= %d\n", a->b->nb); 
    if (a->b->nb == 1) {
        printf("zz = %d\n",a->a->i);
        printf("%d %d\n", a->count, is_tried(a->a));
        exit(0);
    }
    if (is_b_tried(a->b, b)) {
        while (a->b->nb == b)
            grap(a,"pa", pa);
        return 1;
    }


    while (count_nb(a->b, b) > 2 && have_pivot(a->b, p)){
        printf("non\n");
        if (a->b->i >=  p) 
            grap(a, "pa", pa);
        else 
            grap(a, "rb", rb);     
    }
    go_max(a);
    f3(a, b);
    return 1;
}

int start_all (t_piles *a) {
    //int i;

    /*while (a->b) {
        printf("%d\n", a->b->nb);
        a->b = a->b->next;
    }*/
                printf("i endouille %d\n",count_nb(a->b, a->b->nb));

    while (a->b) {
        
        if (a->b->nb == 1) {
            exit(0);
        }
        if (count_nb(a->b, a->b->nb) > 3) {
                        printf("endouillette\n");

            ender(a);
        } else {
            printf("endouilleron %d \n", a->b->nb);
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
    return 1;
}