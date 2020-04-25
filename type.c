#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_pile {
    int *pile;
    int index;
}   t_pile;

typedef struct s_piles {
    t_pile *a;
    t_pile  *b;
}   t_piles;

#endif