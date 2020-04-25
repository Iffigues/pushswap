#ifndef FT_SWAP_H
# define FT_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define ERROR "Error\n"
# define MAX_POS "2147483647"
# define MAX_NEG "2147483648"

typedef struct s_pile {
    int *pile;
    int max_size;
    int size;
    int index;
}   t_pile;

typedef struct s_piles {
    t_pile *a;
    t_pile  *b;
}   t_piles;

char **split(char *a);
int ft_strlen(char *b);
void ft_putstr(char *b);
int verif_int(char **b);
int verif(char *b);
int count_array(char **b);
void ft_putchar(char c);
int ft_atoi(char *str);
t_piles  *new_piles(char **b);
#endif