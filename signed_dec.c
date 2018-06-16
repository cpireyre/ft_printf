/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:16:02 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/16 10:45:43 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "inttypes.h"

void	pad_left(t_printf *a, intmax_t i)
{
	size_t	digits;
	int		to_pad;
	t_bool	sign;
	int		diff;

	digits = ft_count_digits_base(i, 10);
	sign = (a->op.fl & (FLAG_PLUS | FLAG_SPACE)) || (i < 0);
	to_pad = a->op.fw - (ft_max(digits, a->op.prec) + sign);
	diff = a->op.prec - digits;
	if (!(a->op.fl & FLAG_DASH) && !(a->op.fl & FLAG_ZERO) && (to_pad > 0))
		repeat_buf(&a->buf, ' ', to_pad);
	if (i < 0)
		putc_buf(&a->buf, '-');
	else if (a->op.fl & FLAG_PLUS)
		putc_buf(&a->buf, '+');
	else if (a->op.fl & FLAG_SPACE)
		putc_buf(&a->buf, ' ');
	if ((to_pad > 0) && (a->op.fl & FLAG_ZERO))
		repeat_buf(&a->buf, '0', to_pad);
	if (diff > 0)
		repeat_buf(&a->buf, '0', diff);
}

void	pad_right(t_printf *a, intmax_t i)
{
	size_t	digits;
	int		to_pad;
	t_bool	sign;
	int		diff;

	digits = ft_count_digits_base(i, 10);
	sign = (a->op.fl & (FLAG_PLUS | FLAG_SPACE)) || (i < 0);
	to_pad = a->op.fw - (ft_max(digits, a->op.prec) + sign);
	if ((to_pad > 0) && (a->op.fl & FLAG_DASH))
		repeat_buf(&a->buf, ' ', to_pad);
}

void	itoa_buf(intmax_t i, t_buf *buf)
{
	size_t	digits;
	char	num[32];
	t_bool	negative;

	ft_bzero(num, sizeof(char) * 11);
	digits = ft_count_digits_base(i, 10);
	if (i < 0)
		i = ~i + 1;
	while (digits)
	{
		num[digits - 1] = ((i % 10) + '0');
		i /= 10;
		digits--;
	}
	putstr_buf(buf, num);
}

void	signed_dec(t_printf *arg)
{
	intmax_t	i;

	if (arg->op.length_mod & MOD_J)
		i = va_arg(*(arg->ap), intmax_t);
	else if (arg->op.length_mod & MOD_Z)
		i = va_arg(*(arg->ap), size_t);
	else if (arg->op.length_mod & MOD_LL)
		i = va_arg(*(arg->ap), long long int);
	else if (arg->op.length_mod & MOD_L)
		i = va_arg(*(arg->ap), long int);
	else if (arg->op.length_mod & MOD_HH)
		i = (char)va_arg(*(arg->ap), int);
	else if (arg->op.length_mod & MOD_H)
		i = (short int)va_arg(*(arg->ap), int);
	else
		i = va_arg(*(arg->ap), int);
	if ((arg->op.prec > 0) || (arg->op.fl & FLAG_DASH))
		arg->op.fl &= (arg->op.fl & ~FLAG_ZERO);
	pad_left(arg, i);
	itoa_buf(i, &arg->buf);
	pad_right(arg, i);
}
