/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 02:51:41 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/20 21:04:48 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;
void push(int data)
{
    if (top == MAX - 1)
    {
        printf("stack overflow\n");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;   
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    // push(0);
    int i = top;
    while(i >= 0)
    {
        printf("%d\n",stack_arr[i]);
        i--;
    }
    
}
