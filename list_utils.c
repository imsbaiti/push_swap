/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:00:39 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/26 16:17:48 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value)
{
	t_list *new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
void ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list *temp;
	if (!lst || !new_node)
		return;
	if (*lst == NULL)
	{
		*lst = new_node;
		return;
	}
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
}

void	ft_lstclear(t_list **lst) 
{
	t_list *temp;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}
int is_duplicate(t_list *lst, int value)
{
	while (lst)
	{
		if (lst->value == value)
			return (1);
		lst = lst->next;
	}
	return (0);
}