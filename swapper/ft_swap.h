#ifndef FT_SWAP_H
# define FT_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# define ERROR "Error\n"
# define MAX_POS "2147483647"
# define MAX_NEG "2147483648"
# include <stdio.h>

typedef struct s_pile {
    int i;
    int nb;
    int fixe;
    int y;
    struct s_pile  *next;
    struct s_pile *prev;
}   t_pile;

typedef struct s_piles {
    t_pile *a;
    t_pile  *b;
    int nb;
    int size;
    int count;
}   t_piles;

void fixed(t_pile *a);
int get_sens(t_pile *a, int p, int i);
int make_end(t_piles *a);
int start_all(t_piles *a);
void grap(t_piles *a, char *b,  void (*pf)(t_piles *));
void step_trois(t_piles *a);
int is_rev_tried(t_pile *a);
void ra(t_piles *a);
int count_list(t_pile *a);
int get_pivot(t_pile *a);
int errors();
void rb(t_piles *a);
void rr(t_piles *a);
int free_pile(t_piles *a);
void free_array(char **b);
t_pile	*ft_lstnew(int b, int t);
void    ft_lstadd(t_pile **a, int b, int c);
char **split(char *a);
int ft_strlen(char *b);
void ft_putstr(char *b);
int verif_int(char **b);
int verif(char *b);
void rb(t_piles *a);
void rr(t_piles *a);
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
void rra(t_piles *b);
void rrb(t_piles *b);
void rrr(t_piles *b);
int start(t_piles *a);
int is_tried(t_pile *a);
int get_min(t_pile *a);
int get_max(t_pile *a);
void go_min(t_piles *a);
int make_one(t_piles *a);
void f3(t_piles *a, int i);
int ender(t_piles *a);
void tri(t_piles *a);
#endif