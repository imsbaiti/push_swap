/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:26:28 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/21 00:12:24 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_sorted(t_stack **a)
{
    t_stack *tmp;
    
    tmp = *a;
    while (tmp->next)
    {
        if (tmp->value > tmp->next->value)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void    first_node(t_stack **a, char **res, int data)
{
    *a = ft_lstnew(data);
    if (!(*a))
        return (ft_free(res), exit(1));
}

void    ft_free(char **av)
{
    int i;

    i = 0;
    while (av[i])
    {
        free(av[i]);
        i++;
    }
    free(av);
}

int check_double(char **av)
{
    int i;
    int j;

    i = 0;
    while (av[i])
    {
        j = i + 1;
        while (av[j])
        {
            if (ft_atoi(av[i]) == ft_atoi(av[j]))
            {
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}
void    ft_file(t_stack **a, char **res)
{
    long    r;
    int     size;
    int     i;
    t_stack *tmp;

    i = 0;
    size = ft_strlen2(res);
    while (i < size)
    {
        if (ft_atoi(res[i] > INT_MAX) || ft_atoi(res[i] < INT_MIN))
            return (write(2, "Error\n", 6), ft_free(res),exit(1));
        r = (int)ft_atoi(res[i]);
        if (i == 0)
            first_node(a, res, r);
        else
        {
            tmp = ft_lstnew(r);
            if (!tmp)
                return (free(a), ft_free(res), exit(1));
            ft_lstadd_back(a, tmp);
        }
        i++;
    }
}