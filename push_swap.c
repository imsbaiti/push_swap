/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 02:51:41 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/26 16:50:36 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
int main(int argc, char **argv)
{
    t_list *lst;
    t_list *temp;

   if (argc > 1)
    {
    
        lst = list(argv + 1);
        
        if (lst == NULL)
        {
            write(2, "Error\n", 6);
            return 1;
        }

        printf("Linked list values:\n");
        temp = lst;
        while (temp != NULL)
        {
            printf("%d\n", temp->value); 
            temp = temp->next;
        }
        ft_lstclear(&lst);
    }
    return 0;
}

