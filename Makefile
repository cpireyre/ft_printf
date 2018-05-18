# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 09:44:26 by cpireyre          #+#    #+#              #
#    Updated: 2018/05/18 12:06:03 by cpireyre         ###   ########.fr        #
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

PARSE		=	parse
PARSE_FILES	=	parse.c
PARSE_OBJ	=	$(PARSE)/$(PARSE_FILES:.c=.o)

$(PARSE_OBJ)%.o: $(PARSE)/$(PARSE_FILES)%.c
	mkdir $(PARSE)/obj/ 2> /dev/null || true
	$(CC) $(CFLAGS) $(BFLAGS) $@ $<

OBJ			=	$(PARSE_OBJ)

parse:	$(PARSE_OBJ)

clean:
	$(RM) $(OBJ)
