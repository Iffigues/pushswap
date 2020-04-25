#include "ft_swap.h"

int verif(char *b) {
    while (*b) {
        if ((*b > '9' || *b < '0') && *b != ' ' ) {
            return (0);
        }
        b++;
    }
    return (1);
}