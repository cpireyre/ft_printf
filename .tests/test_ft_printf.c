/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:06:25 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/14 10:11:42 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_putendl("Testing %d...");
	ft_printf("4:%d\n", 4);
	ft_printf("0:%d\n", 0);
	ft_printf("-42:%d\n", -42);
	ft_printf("2147483647:%d\n", 2147483647);
	ft_printf("4 with prec, no 0:%0.7d\n", 4);
	ft_printf("4 without prec, yes 0:%0d\n", 4);
	ft_printf("4 with dash, no 0:%0++-  #10i\n", 4);
	ft_printf("4 without dash, yes 0:%0++  #10i\n", 4);
	ft_printf("5, -5 with space:% d % i\n", 5, -5);
	ft_printf("5, -5 without space:%d %i\n", 5, -5);
	ft_printf("%+06d\n", -1337);
	printf("%+06d\n", -1337);
//
//	ft_putendl("Testing return values for basic strings...");
//	ft_assert(ft_printf("1") == printf("1"));
//	ft_assert(ft_printf("") == printf(""));
//	ft_assert(ft_printf("fuck\n") == printf("fuck\n"));
//
//	ft_putendl("\n\x1b[0mTesting %%...");
//	ft_assert(ft_printf("%%o\n", 123456) == printf("%%o\n", 123456));
//	ft_assert(ft_printf("%%%%o\n", 123456) == printf("%%%%o\n", 123456));
	return (0);
}
