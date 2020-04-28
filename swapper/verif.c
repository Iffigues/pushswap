#include "ft_swap.h"

int count_array(char **b) {
    int i;

    i = 0;
    while (b[i])
        i++;
    return i;
}

int ft_compare(char *a, char *b) {
    int i;

    i = 0;
    while (a[i]) {
        if (a[i] > b[i])
            return 0;
        i++;
    }
    return 1;
}

int ft_int(char *b) {
    int a;
    int h;

    h = 0;
    if (*b == '-')
        h = 1;
    if (*b == '+' || *b == '-')
        b++;
    a = ft_strlen(b);
    if (!a || a > ft_strlen(MAX_POS))
        return 0;
 
    if (a == ft_strlen(MAX_POS)) {
        if (h == 0)
            return ft_compare(b, MAX_POS);
        return ft_compare(b, MAX_NEG);
    }

    return 1;
}

int verif_char(char *b) {

    if (b == NULL || ft_strlen(b) == 0)
        return 0;
    if (*b == '+' || *b == '-') 
        b++;

    while (*b)
        if (*b > '9' || *b++ < '0')
            return 0;
    return 1;
}

int verif_int(char **b) {
    if (b == NULL)
        return 0;
    while (*b)
        if (!verif_char(*b) || !ft_int(*b++))
            return 0;
    return 1;
}