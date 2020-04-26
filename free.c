#include "ft_swap.h"

void free_array(char **b) {
    int i;

    i = 0;
    while (b[i])
        free(b[i++]);
    free(b);
}