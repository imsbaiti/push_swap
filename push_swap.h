#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>


typedef struct s_stack
{
    int    x;
    int     price;
    int     budjet;
    int     value;
    struct s_stack *next;
    struct s_stack *target;
}               t_stack;


/* libft utils */
char **ft_split(char const *s, char c);
int ft_atoi(const char *str);
int ft_isdijit(char c);
int find_spaces(char *str);
void    free_2dim(char **buff);
int ft_strcmp(char *s1, char *s2);
/* for parcing */
int ft_parcing(char **av);
























#endif