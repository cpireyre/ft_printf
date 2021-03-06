/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:43:19 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/20 14:26:54 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int		main(void)
{
	int	meme = 0;

	setlocale(LC_ALL, "");
	ft_printf("><%8.8ls>------------<\n", L"最終的なフラッシュ");
	printf("><%8.8ls>------------<\n", L"最終的なフラッシュ");
	return (0);
}
