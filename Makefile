# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 09:44:26 by cpireyre          #+#    #+#              #
#    Updated: 2018/07/19 11:29:30 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

CC			=	gcc
RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)
BFLAGS		=	-c -o
INCLUDES	=	-I./libft/ -I.

NAME		=	libftprintf.a
LIBDIR		=	./libft
LIBFT		=	$(LIBDIR)/libft.a

SRC_FILES	=	buf.c buf_unicode.c cc.c conversions.c ddioo.c debug.c \
				ft_printf.c get_op.c integer_conversions.c print_int_conv.c \
				ss.c uuxx.c get_int_data.c
OBJ			=	$(SRC_FILES:%.c=%.o)
H_FILES		=	buf.h conversions.h ft_printf.h integer_conversions.h libft.h
D_FILES		=	$(SRC_FILES:%.c=%.d)

all: $(NAME)

force:
	@true

$(LIBFT): force
	@$(MAKE) -C $(LIBDIR) > /dev/null

$(NAME): $(LIBFT) $(OBJ) 
	@echo "Compiling libftprintf."
	@libtool -static -o $@ $^
	@echo "Also done!"

%.o: %.c $(H_FILES)
	@$(CC) $(CFLAGS) $(BFLAGS) $@ $< $(INCLUDES)

clean:
	@$(RM) $(OBJ) $(D_FILES)
	@echo "Removing object files."

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBDIR)
	@echo "All clean."

re: fclean all

.PHONY: all, clean, fclean, re, force
