/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:45:23 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/21 01:25:33 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_list(char **str)
{
    int i;
    int j;
    
    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        j = 0;
        if (find_spaces(str[i]))
            return (1);
        if (str[i][j] == '+' || str[i][j] == '-')
            j++;
        if (!str[i][j])
            return (1);
        while (str[i][j])
        {
            if (str[i][j] < '0' || str[i][j] > '9')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

long    *increase_arr(long *nbr, char **buff, int *size)
{
    int     i;
    int     new_size;
    long    *new_arr;
    
    i = 0;
    new_size = *size;
    while (buff[i])
        i++;
    new_size += i;
    new_arr = malloc(sizeof(long) * new_size);
    if (!new_arr)
        return (free(nbr), NULL);
    i = -1;
    while (++i < *size)
        new_arr[i] = nbr[i];
    free(nbr);
    i = -1;
    while (buff[++i])
    {
        new_arr[*size] = ft_atoi(buff[i]);
        if (ft_strcmp(buff[i], "-1") && new_arr[*size] == -1)
            return (free(new_arr), free_2adim(buff), NULL);
        (*size)++;
    }
    return (new_arr);
}

long    *arr_of_nbrs(char **str, int *size)
{
    int i;
    long    *nbr;
    char    **buff;
    
    i = 0;
    *size = 0;
    nbr = NULL;
    while (str[++i])
    {
        buff = ft_split((const char *)str[i], ' ');
        if (check_list(buff) || !buff[0] || !buff)
        {
            if (nbr)
                free(nbr);
            return (free_2dim(buff), NULL);
        }
        nbr = increase_arr(nbr, buff,size);
        if (!nbr)
            return (NULL);
        free_2dim(buff);
        if (!nbr)
            return (NULL);
    }
    return (nbr);
}

int nbr_is_repeat(long *nbr, int size)
{
    int i;
    int j;
    
    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (nbr[i] == nbr[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_parcing(char **av)
{
    long    *nbr;
    int     size;

    nbr = arr_of_nbrs(av, &size);
    if (!nbr)
        return (0);
    if (nbr_is_repeat(nbr, size))
        return (free(nbr), 0);
    free (nbr);
    return (1);
}
