/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:06:25 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/14 07:52:30 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_putendl("Testing %d...");
	ft_printf("%d\n", 4);
	ft_printf("with precision, no 0: %0.7d\n", 4);
	ft_printf("without precision, yes 0: %0d\n", 4);
	ft_printf("with dash, no 0:%0++-  #10i\n", 4);
	ft_printf("without dash, yes 0: %0++  #10i\n", 4);
	ft_printf("with space % d % i\n", 5, -5);
	ft_printf("without space %d %i\n", 5, -5);
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
