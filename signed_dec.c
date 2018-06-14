/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:16:02 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/14 07:53:27 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_flags(t_printf *a, int i)
{
	int		digits;
	int		toprint;

	digits = ft_count_digits_base(i, 10);
	toprint = a->options.field_width - digits;
	if (i >= 0 && 
		(a->options.flags & FLAG_PLUS) || (a->options.flags & FLAG_SPACE))
	{
		putchar_buffer(&a->buffer, (a->options.flags & FLAG_PLUS) ? '+' : ' ');
		toprint--;
	}
	if (toprint > 0 && (a->options.flags & FLAG_ZERO)
			&& !(a->options.flags & FLAG_DASH))
		repeat_buffer(&a->buffer, '0', toprint);
}

void		signed_dec(t_printf *arg)
{
	int		i;

	i = va_arg(*(arg->ap), int);
	do_flags(arg, i);
	ft_putnbr(i);
}
