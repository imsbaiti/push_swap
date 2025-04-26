/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:47:05 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/26 16:21:37 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *list(char **nums)
{
    t_list	*ls;
    t_list 	*node;
    char 	**arr;
    int 	i;
	int 	j;
	long 	num;

	i = -1;
	ls = NULL;
	
	while (nums[++i] != NULL)
	{
		if (!ft_check_args(nums[i]))
			return (ft_putstr("Error: not number\n") , NULL);
		arr = ft_split(nums[i], ' ');
		if (arr == NULL || arr[0] == NULL)
			return (ft_lstclear(&ls), ft_free(arr), NULL);
		j = -1;
		while (arr[++j] != NULL)
		{
			if (ft_strlen(arr[j]) > 11)
				return (ft_putstr("Error\n"), ft_lstclear(&ls), ft_free(arr), NULL);
			num = ft_atoi(arr[j]);
			if (num > INT_MAX || num < INT_MIN)
				return (ft_putstr("Error\n"), ft_lstclear(&ls), ft_free(arr), NULL);
			if (is_duplicate(ls, num))
				return (ft_lstclear(&ls), ft_free(arr), NULL);
			node = create_node(num);
			if (node == NULL)
				return (ft_lstclear(&ls), ft_free(arr),NULL);
			ft_lstadd_back(&ls, node);
		}
		ft_free(arr);
	}
	return (ls);
}