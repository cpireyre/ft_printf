/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:03:10 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/18 11:03:11 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void	ft_putchar_unicode(wchar_t uchar)
{
	if (uchar < 128)
		ft_putchar(uchar);
	else if (uchar < 2048)
	{
		ft_putchar(0b11000000 | ((uchar >> 6) & 0b00011111));
		ft_putchar(0b10000000 | (uchar & 0b00111111));
	}
	else if (uchar < 1048576)
	{
		ft_putchar(0b11100000 | ((uchar >> 12) & 0b00001111));
		ft_putchar(0b10000000 | ((uchar >> 6) & 0b00111111));
		ft_putchar(0b10000000 | (uchar & 0b00111111));
	}
	else
	{
		ft_putchar(0b11110000 | ((uchar >> 15) & 0b00000111));
		ft_putchar(0b10000000 | ((uchar >> 12) & 0b00111111));
		ft_putchar(0b10000000 | ((uchar >> 6) & 0b00111111));
		ft_putchar(0b10000000 | (uchar & 0b00111111));
	}
}
		
int	main(void)
{
	size_t	i;

	i = 20000;
	setlocale(LC_ALL, "");
	while (i < 20010)
	{
		ft_putchar_unicode(i);
		printf("%lc\n", (wint_t)i);
		i++;
	}
	return (0);
}
