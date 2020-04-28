#ifndef FT_SWAP_H
# define FT_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# define ERROR "Error\n"
# define MAX_POS "2147483647"
# define MAX_NEG "2147483648"

typedef struct s_pile {
    int i;
    struct s_pile  *next;
    struct s_pile *prev;
}   t_pile;

typedef struct s_piles {
    t_pile *a;
    t_pile  *b;
}   t_piles;

int errors();
int free_pile(t_piles *a);
void free_array(char **b);
t_pile	*ft_lstnew(int b);
void    ft_lstadd(t_pile **a, int b);
char **split(char *a);
int ft_strlen(char *b);
void ft_putstr(char *b);
int verif_int(char **b);
int verif(char *b);
int count_array(char **b);
void ft_putchar(char c);
int ft_atoi(char *str);
t_piles  *new_piles(char **b);
int *make_array_int (char **b);
void sa(t_piles *a);
void sb(t_piles *a);
void ss(t_piles *a);
void pa(t_piles *a);
void pb(t_piles *b);
int start(t_piles *a);

#endif