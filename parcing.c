/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:22:53 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/20 23:26:50 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_dijit(int x)
{
    if (x >= '0' && x <= '9')
        return (1);
    else
        return(0);
}

int ft_is_valid_dijit(char **args)
{
    int i;
    int j;

    i = 0;
    while (args[i])
    {
        j = 0;
        if (args[1][j] == '-' || args[1][j] == '+')
            j++;
        if (!args[1][j])
            return(0);
        while (args[i][j])
        {
            if (!ft_dijit(args[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
int ft_isspace(char **args)
{
    int i;
    int j;

    i = 0;
    while (args[i])
    {
        j = 0;
        while (args[i][j])
        {
            if ((args[i][j] >= 9 && args[i][j] <= 13) || args[i][j] == 32)
                return(0);
            j++;
        }
        i++;
    }
    return (1);
}

void    ft_parcing(char **av)
{
    int i;
    char *tmp;
    int num;

    num = 0;
    i = 0;
    if (!ft_is_dijit(av))
        return (write(2, "Error\n", 6), ft_free(av), exit(1));
    if (!ft_isspace(av))
        return(write (2, "Erroe\n", 6), ft_free(av), exit(1));
    if (check_double(av))
        return (write (2, "Error\n", 6), ft_free(av), exit(1));
    while (av[i])
    {
        num = ft_atoi(av[i]);
        tmp = ft_itoi(num);
        if (!tmp)
            return (write(2, "Error\n", 6), ft_free(av), exit(1));
        free(av[i]);
        av[i] = tmp;
        i++;
    }
}