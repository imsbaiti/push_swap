# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/20 23:28:11 by imsbaiti          #+#    #+#              #
#    Updated: 2025/04/26 16:35:08 by imsbaiti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c ft_split.c parsing.c \
	utilis1.c utilis2.c list_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
