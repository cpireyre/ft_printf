/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:06:25 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/12 13:05:24 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_assert(t_bool condition)
{
	if (condition == true)
		ft_putstr("\x1b[32m[OK]");
	else
		ft_putstr("\x1b[31m[error]");
}

int		main(void)
{
	ft_putendl("Testing return values for basic strings...");
	ft_assert(ft_printf("1") == printf("1"));
	ft_assert(ft_printf("") == printf(""));
	ft_assert(ft_printf("fuck\n") == printf("fuck\n"));

	ft_putendl("\n\x1b[0mTesting %%...");
	ft_assert(ft_printf("%%o\n", 123456) == printf("%%o\n", 123456));
	ft_assert(ft_printf("%%%%o\n", 123456) == printf("%%%%o\n", 123456));
	return (0);
}
