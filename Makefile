# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/20 23:28:11 by imsbaiti          #+#    #+#              #
#    Updated: 2025/04/20 23:41:42 by imsbaiti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = mandatory/push_swap.c mandatory/ft_atoi.c mandatory/ft_parcing.c \
	mandatory/ft_itoi.c mandatory/ft_file.c ft_struct_utilis1.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
		$(CC) $(CFLAGS) -c $ -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
	