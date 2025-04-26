/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:48:32 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/26 16:19:12 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write (1, &str[i],1);
        i++;
    }
}
int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
    {
        len++;
    }
    return (len);
}
void    ft_free(char **arr)
{
    int i;

    i = 0;
    if (!arr)
        return ;
    i = 0;
    while (arr[i] != NULL)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}

int ft_check_args(char *str)
{
	int i = -1;
	while (str[++i])
	{
		if(str[i] != ' ' && !ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return 0;
		if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
			return (0);
	}
	return 1;
}
