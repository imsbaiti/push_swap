#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
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


int ft_is_valid_dijit(char **args);
void ft_parcing(char **av);
int ft_isspace(char **args);
char    *ft_itoa(int n);
int check_double(char **av);
int ft_atoi(const char *str);
int ft_dijit(int x);









#endif