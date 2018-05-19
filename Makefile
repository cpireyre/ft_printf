# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 09:44:26 by cpireyre          #+#    #+#              #
#    Updated: 2018/05/18 14:31:27 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

CC			=	gcc
RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror $(SANITIZE) $(INCLUDES)
BFLAGS		=	-c -o
SANITIZE	=	-fsanitize=address -fsanitize=undefined
INCLUDES	=	-I./libft/ -I./parse/

NAME		=	libftprintf

PARSE_PATH	=	./parse/
PARSE_FILES	=	parse.c tests.c
PARSE_OBJ	=	$(PARSE_FILES:.c=.o)
PARSE		=	$(addprefix $(PARSE_PATH),$(PARSE_OBJ))

$(PARSE_PATH)%.o: $(PARSE_PATH)%.c
	$(CC) $(CFLAGS) $(BFLAGS) $@ $<

OBJ			=	$(PARSE_OBJ)

parse:	$(PARSE)
	$(CC) $(CFLAGS) -o tests/parse_test.out $(PARSE) -L./libft/ -lft

clean:
	$(RM) $(PARSE)
