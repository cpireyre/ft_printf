/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:16:02 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/17 09:38:55 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "inttypes.h"

void			pad_left(t_printf *a, t_integer_data id)
{
	if (!(a->op.fl & FLAG_DASH) && !(a->op.fl & FLAG_ZERO) && (id.to_pad > 0))
		repeat_buf(&a->buf, ' ', id.to_pad);
	if (id.num < 0)
		putc_buf(&a->buf, '-');
	else if (a->op.fl & FLAG_PLUS)
		putc_buf(&a->buf, '+');
	else if (a->op.fl & FLAG_SPACE)
		putc_buf(&a->buf, ' ');
	if (id.num != 0 && (id.base == 8 || id.base == 16))
	{
		putc_buf(&a->buf, '0');
		if (id.base == 16)
			putc_buf(&a->buf, (a->conv == 'x') ? 'x' : 'X');
	}
	if ((id.to_pad > 0) && (a->op.fl & FLAG_ZERO))
		repeat_buf(&a->buf, '0', id.to_pad);
	if (id.diff_prec > 0)
		repeat_buf(&a->buf, '0', id.diff_prec);
}

void			pad_right(t_printf *a, t_integer_data id)
{
	if ((id.to_pad > 0) && (a->op.fl & FLAG_DASH))
		repeat_buf(&a->buf, ' ', id.to_pad);
}

void			itoa_buf(t_buf *buf, t_integer_data id)
{
	char	number[256];
	char	*basestr;
	t_bool	negative;

	ft_bzero(number, sizeof(char) * 256);
	basestr = "0123456789abcdef";
	if (id.num < 0)
		id.num = ~id.num + 1;
	while (id.digits)
	{
		number[id.digits - 1] = basestr[(id.num % id.base)];
		id.num /= id.base;
		id.digits--;
	}
	putstr_buf(buf, number);
}

intmax_t		get_cast(t_printf *arg)
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
	return (i);
}

char			get_base(char conv)
{
	if (conv == 'o' || conv == 'O')
		return (8);
	else if (conv == 'x' || conv == 'X')
		return (16);
	else
		return (10);
}

t_integer_data	get_int_data(t_printf *a)
{
	t_integer_data	id;

	id.num = get_cast(a);
	id.base = get_base(a->conv);
	id.digits = ft_count_digits_base(id.num, id.base);
	id.display_sign = (a->op.fl & (FLAG_PLUS | FLAG_SPACE)) || (id.num < 0);
	id.to_pad = a->op.fw - (ft_max(id.digits, a->op.prec) + id.display_sign);
	id.diff_prec = a->op.prec - id.digits;
	return (id);
}

void			integer_conversion(t_printf *a)
{
	t_integer_data	id;

	if ((a->op.prec > 0) || (a->op.fl & FLAG_DASH))
		a->op.fl &= (a->op.fl & ~FLAG_ZERO);
	id = get_int_data(a);
	pad_left(a, id);
	itoa_buf(&a->buf, id);
	pad_right(a, id);
}

void			signed_dec(t_printf *arg)
{
	integer_conversion(arg);
}

void			l_signed_dec(t_printf *arg)
{
	arg->op.length_mod |= MOD_L;
	signed_dec(arg);
}
