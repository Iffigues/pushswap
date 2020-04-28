#include "ft_swap.h"

int *make_array_int (char **b) {
    int *g;
    int i;
    int c;

    i = count_array(b);
     if (!(g = (int *)malloc(sizeof(int) * i)))
        return NULL;
    c = 0;
    while (b[c]){
        g[c] = ft_atoi(b[c]);
        c++;
    }
  return g;
}