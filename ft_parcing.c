/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:45:23 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/21 21:41:11 by imsbaiti         ###   ########.fr       */
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
    nbr = NULL; //nbr is a pointer to long, initially set to NULL. It will eventually hold the array of parsed numbers.
    while (str[++i])// Loop through each string in the input array The loop starts at str[1] because str[0] is typically the program name (argv[0]).
    {
        buff = ft_split((const char *)str[i], ' '); //For example, if str[i] = "42 -123 56", buff will become ["42", "-123", "56"]
        if (check_list(buff) || !buff[0] || !buff)// Check if the split string is valid, if not, return NULL after cleanup
        { //check_list(buff) checks if the split parts are valid numbers (i.e., no non-numeric characters).

                /*!buff[0] checks if the buff array is empty (i.e., there were no valid substrings).

                    /*!buff checks if the split failed (i.e., ft_split returned NULL).8*/
            if (nbr)
                free(nbr);
            return (free_2dim(buff), NULL);/* Free the split strings and return NULL on error*/ //Free the memory allocated for buff using free_2dim(buff)
        }
        nbr = increase_arr(nbr, buff,size);// Increase the array of numbers by converting the split strings to numbers
        if (!nbr)
            return (NULL);
        free_2dim(buff);// Free the memory allocated for the split strings
        if (!nbr)
            return (NULL); 
    }
    return (nbr);// Return the parsed array of numbers
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

    nbr = arr_of_nbrs(av, &size);// Return the parsed array of numbers
    if (!nbr)
        return (0);
    if (nbr_is_repeat(nbr, size))
        return (free(nbr), 0);
    free (nbr);
    return (1);
}
