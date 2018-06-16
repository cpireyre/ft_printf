# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 09:44:26 by cpireyre          #+#    #+#              #
#    Updated: 2018/06/16 09:42:42 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

CC			=	gcc
RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror $(SANITIZE) $(INCLUDES)
BFLAGS		=	-c -o
SANITIZE	=	-fsanitize=address -fsanitize=undefined
INCLUDES	=	-I./libft/ -I.

NAME		=	libftprintf.a

SRC_FILES	=	buf.c conversions.c debug.c ft_printf.c get_op.c signed_dec.c
SRC			=	$(SRC_FILES:%.c=%.o)

all:
	gcc *.c -c -Ilibft/ -I./
	gcc libft/*.c -c -Ilibft/ -I./
	ar rc $(NAME) *.o libft/obj/*.o
	ranlib $(NAME)
