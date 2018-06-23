# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 09:44:26 by cpireyre          #+#    #+#              #
#    Updated: 2018/06/23 10:52:57 by cpireyre         ###   ########.fr        #
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
LIBDIR		=	./libft
LIBFT		=	$(LIBDIR)/libft.a

SRC_FILES	=	buf.c buf_unicode.c cc.c conversions.c ddioo.c debug.c \
				ft_printf.c get_op.c integer_conversions.c print_int_conv.c \
				ss.c uuxx.c
OBJ			=	$(SRC_FILES:%.c=%.o)

$(NAME): $(LIBFT) $(OBJ) 
	@echo "Compiling libftprintf."
	@libtool -static -o $@ $^
	@echo "Also done!"

all: $(NAME)

$(LIBFT):
	make -C $(LIBDIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(BFLAGS) $@ $< $(SANITIZE) $(INCLUDES)

clean:
	@$(RM) $(OBJ)
	@echo "Removing object files."

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBDIR)
	@echo "All clean."

re: fclean all

.PHONY: all, clean, fclean, re
