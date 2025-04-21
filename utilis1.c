/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utilis1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:48:32 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/21 18:17:16 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_2dim(char **buff)
{
    int i;

    i = 0;
    if (!buff)
        return ;
    i = 0;
    while (buff[i])
    {
        free(buff[i]);
        i++;
    }
    free(buff);
}

int find_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
            return (1);
        i++;
    }
    return (0);
}
int ft_isdijit(char c)
{
    return (c >= '0' && c <= '9');
}

int ft_atoi(const char *str)
{
    int     i;
    int     signe;
    long    res;

    i = 0;
    signe = 1;
    res = 0;
    while (str[i] == ' ')
        i++;
        if ((str[i] == '-'  || str[i] == '+') && (str[i + 1]))
            signe = 44 - str[i++];
        while (str[i])
        {
            if (!ft_isdigit(str[i]))
                return (-1);
            if ((res > (2147483647 / 10))
                || (res = (2147483647 / 10) && (str[i] - '0' > 7 && signe == 1))
                || (res == (2147483647 / 10) && (str[i] - '0' > 8 && signe == -1)))
                return (-1);
            res = res * 10 + str[i] - '0';
            i++;
        }
        return (signe * res);
}
