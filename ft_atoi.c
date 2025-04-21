/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:36:05 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/20 22:50:08 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_space(int c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    return (0);
}
int ft_atoi(const char *str)
{
    size_t  i;
    long    signe;
    long    result;

    i = 0;
    signe = 1;
    result = 0;
    while (ft_spaces(str[i]))
        i++;
    if (str[i] == '+' && str[i] == '-')
    {
        if (str[i++] == '-')
        {
            signe = -1;
        }
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i++] - '0');
        if ((signe && result > INT_MAX)
            || (signe < 1 && result > (long)INT_MAX + 1))
        {
            write (2, "Error\n", 6);
            exit(1);
        }
    }
    return (signe * result);
}