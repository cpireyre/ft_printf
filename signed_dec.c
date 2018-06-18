/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:16:02 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/18 09:46:52 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "inttypes.h"
#include "integer_conversions.h"

void			itoa_buf(t_buf *buf, t_integer_data id)
{
	char	number[256];
	char	*basestr;
	t_bool	negative;

	ft_bzero(number, sizeof(char) * 256);
	basestr = id.caps ? "0123456789ABCDEF" : "0123456789abcdef";
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

void			utoa_buf(t_buf *buf, t_integer_data id)
{
	char	number[256];
	char	*basestr;
	t_bool	negative;

	ft_bzero(number, sizeof(char) * 256);
	basestr = id.caps ? "0123456789ABCDEF" : "0123456789abcdef";
	while (id.digits)
	{
		number[id.digits - 1] = basestr[(id.unum % id.base)];
		id.unum /= id.base;
		id.digits--;
	}
	putstr_buf(buf, number);
}

void			pad_left(t_printf *a, t_integer_data id)
{
	if (!(a->op.fl & FLAG_DASH) && !(a->op.fl & FLAG_ZERO) && (id.to_pad > 0))
		repeat_buf(&a->buf, ' ', id.to_pad);
	if (!(id.u) && id.num < 0)
		putc_buf(&a->buf, '-');
	else if (a->op.fl & FLAG_PLUS)
		putc_buf(&a->buf, '+');
	else if (a->op.fl & FLAG_SPACE)
		putc_buf(&a->buf, ' ');
	if (id.alt && id.diff_prec < 1)
	{
		putc_buf(&a->buf, '0');
		if (id.alt == 2)
			putc_buf(&a->buf, (id.caps) ? 'X' : 'x');
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

void			integer_conversion(t_printf *a)
{
	t_integer_data	id;

	if ((a->op.prec > 0) || (a->op.fl & FLAG_DASH))
		a->op.fl &= (a->op.fl & ~FLAG_ZERO);
	id = get_int_data(a);
	pad_left(a, id);
	if (id.u)
		utoa_buf(&a->buf, id);
	else
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

void	u_octal(t_printf *arg)
{
	integer_conversion(arg);
}
