/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:58:25 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/26 16:25:03 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long ft_atoi(const char *str)
{
    long     i;
    long     signe;
    long    res;

    i = 0;
    signe = 1;
    res = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            signe = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + (str[i] - '0');
        i++;
        if (res > INT_MAX && (res * signe) < INT_MIN)
        {
            if (signe == 1)
                return LONG_MAX;
            else
                return LONG_MIN;
        }
    }
    return (signe * res);
        
}
