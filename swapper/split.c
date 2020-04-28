#include "ft_swap.h"


int count(char *a) {
    int i;

    i = 0;
    while (*a) 
        if (*a++ != ' ' && (*a == ' ' || *a == '\0')) 
            i++;
    return i;
}

int my_count(char *b) {
    int i;

    i = 0;
    while (b[i] && b[i] != ' ') {
            i++;
    }
    return i;
}

char *ft_make(char *r) {
    char *t;
    int i;

    i = 0;
    if (!(t = (char *)malloc(sizeof(char) * my_count(r) + 1))) 
        return NULL;
    while (*r && *r != ' ') {
            t[i++] = *r++;
    }
    t[i] = '\0';
    return t;
}

char **split(char *a) {
    char **b;
    int i;

    i = 0;
    printf("%d\n",count(a));
    if (!(b = (char **)malloc(sizeof(char *) * (count(a) + 1)))) 
        return NULL;
    while (*a) {
        while(*a && *a == ' ')
            a++;
        if (*a) 
            b[i++] = ft_make(a);
        while(*a && *a != ' ')
            a++;
    }
    printf("%d\n",i);
    b[i] = NULL;
    return b;
}
