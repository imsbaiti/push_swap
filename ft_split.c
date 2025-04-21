/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:42:06 by imsbaiti          #+#    #+#             */
/*   Updated: 2025/04/21 19:30:51 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t count_word(const char *s, char c)
{
    size_t count;
    int     word;
    
    count = 0;
    word = 0;
    while (*s)
    {
        if (*s != c && !word)
        {
            word = 1;
            count++;
        }
        else if (*s == c)
            word = 0;
        s++;
    }
    return (count);
}

static size_t   calc_len(char const *s, char c)
{
    size_t  i;
    
    i = 0;
    while (s[i] != c && s[i])
        i++;
    return (i);
}

static char *fill_subs(char const **s, char c)
{
    size_t  i;
    char    *subs;
    size_t  len;

    while (**s == c && **s)
        (*s)++;
    len = calcu_len(*s, c);
    subs = (char *) malloc (sizeof (char) * (len + 1));
    if (!subs)
        return (NULL);
    i = 0;
    while (i < len)
    {
        subs[i] = **s;
        i++;
        (*s)++;
    }
    subs[i] = '\0';
    return (subs);
}

static char **free_2_dim(char **str, size_t index)
{
    size_t  i;
    
    i = 0;
    while (i < index)
    {
        free(str[i]);
        i++;
    }
    free(str);
    return (NULL);
}

char **ft_split(char const *s, char c)
{
    size_t words;
    char    **str;
    size_t  i;

    i = 0;
    if (!s)
        return(NULL);
    words = count_words(s, c);
    str = (char **)malloc(sizeof(char *) * (words + 1));
    if (!str)
        return (NULL);
    while (i < words)
    {
        str[i] = fill_subs(&s, c);
        if (!str[i])
            return (free_2_dim(str, i));
        i++;
    }
    str[i] = NULL;
    return (str);
}
