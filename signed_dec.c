/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:16:02 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/14 10:11:42 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_fl(t_printf *a, int i)
{
	size_t	to_pad;
	t_bool	sign;

	to_pad = a->op.fw - ft_count_digits_base(i, 10);
	sign = (a->op.fl & FLAG_PLUS) || (a->op.fl & FLAG_SPACE);
	if (a->op.fl & FLAG_ZERO)
	{
		if (sign)
			putc_buf(&a->buf, (a->op.fl & FLAG_PLUS ? '+' : ' '));
		repeat_buf(&a->buf, '0', to_pad - sign);
	}
}

void		itoa_buf(int i, t_buf *buf)
{
	size_t	digits;
	char	num[11];
	t_bool	negative;

	ft_bzero(num, sizeof(char) * 11);
	negative = (i < 0 ? true : false);
	digits = ft_count_digits_base(i, 10);
	if (negative == true)
		i *= -1;
	while (digits - negative)
	{
		num[digits - 1] = ((i % 10) + '0');
		i /= 10;
		digits--;
	}
	putstr_buf(buf, num);
}

void		signed_dec(t_printf *arg)
{
	int		i;

	i = va_arg(*(arg->ap), int);
	do_fl(arg, i);
	itoa_buf(i, &arg->buf);
}
