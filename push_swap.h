#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>




typedef struct  s_list
{
    int value;
    struct s_list *next;
}       t_list;

/*    parsing       */

t_list *list(char **nums);

/*		Utils for parsing			*/

long	ft_atoi(const char *str);
void	ft_free(char **arr);
char	**ft_split(char const *s, char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_check_args(char *str);
int		ft_isdigit(int i);
int		is_duplicate(t_list *lst, int value);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
t_list	*create_node(int value);





















#endif