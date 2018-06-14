/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:16:02 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/14 13:53:15 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_fl(t_printf *a, int i, t_bool dash)
{
	t_bool	sign;
	int		to_pad;

	if (a->op.fl & FLAG_DASH)
		a->op.fl &= (a->op.fl & ~FLAG_ZERO);
	sign = (a->op.fl & (FLAG_PLUS | FLAG_SPACE)) || (i < 0);
	to_pad = a->op.fw - (ft_count_digits_base(i, 10) + sign);
	if (!dash && to_pad > 0 && !(a->op.fl & (FLAG_ZERO | FLAG_DASH)))
		repeat_buf(&a->buf, ' ', a->op.fw);
	if (i < 0 && !dash)
		putc_buf(&a->buf, '-');
	else if (a->op.fl & FLAG_PLUS && !dash)
		putc_buf(&a->buf, '+');
	else if (a->op.fl & FLAG_SPACE && !dash)
		putc_buf(&a->buf, ' ');
	if ((to_pad > 0) && (a->op.fl & FLAG_ZERO) && !dash)
		repeat_buf(&a->buf, '0', to_pad);
	if (dash && (a->op.fl & FLAG_DASH))
		repeat_buf(&a->buf, ' ', to_pad);
}

void		itoa_buf(int i, t_buf *buf)
{
	size_t	digits;
	char	num[11];
	t_bool	negative;

	ft_bzero(num, sizeof(char) * 11);
	digits = ft_count_digits_base(i, 10);
	i *= (i < 0) ? -1 : 1;
	while (digits)
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
	do_fl(arg, i, false);
	itoa_buf(i, &arg->buf);
	do_fl(arg, i, true);
}
