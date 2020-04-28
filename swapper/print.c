#include "ft_swap.h"

int ft_strlen(char *b) {
    int i;

    i = 0;
    while (b[i])
        i++;
    return i;
}

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putstr(char *b) {
    write(1, b, ft_strlen(b));
}