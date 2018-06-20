/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:39:25 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/20 15:25:03 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

void	(*get_conversion(const char arg))(t_printf *)
{
	size_t	i;

	i = 0;
	while (i < NBR_CONVERSIONS)
	{
		if (g_conversions[i].letter == arg)
			return (g_conversions[i].conversion);
		i++;
	}
	if (DEBUG)
		ft_putendl("Error: couldn't find conversion function.");
	return (NULL);
}

void	putc_buf_unicode(t_buf *buf, wchar_t uchar)
{
	if (uchar < 128)
		putc_buf(buf, uchar);
	else if (uchar < 2048)
	{
		putc_buf(buf, 0b11000000 | ((uchar >> 6) & 0b00011111));
		putc_buf(buf, 0b10000000 | (uchar & 0b00111111));
	}
	else if (uchar < 65536)
	{
		putc_buf(buf, 0b11100000 | ((uchar >> 12) & 0b00001111));
		putc_buf(buf, 0b10000000 | ((uchar >> 6) & 0b00111111));
		putc_buf(buf, 0b10000000 | (uchar & 0b00111111));
	}
	else
	{
		putc_buf(buf, 0b11110000 | ((uchar >> 18) & 0b00000111));
		putc_buf(buf, 0b10000000 | ((uchar >> 12) & 0b00111111));
		putc_buf(buf, 0b10000000 | ((uchar >> 6) & 0b00111111));
		putc_buf(buf, 0b10000000 | (uchar & 0b00111111));
	}
}

void	pad_left_text(t_printf *arg)
{
	if (arg->op.fw > 1 && !(arg->op.fl & FLAG_DASH))
		repeat_buf(&arg->buf, ' ', arg->op.fw - 1);
}

void	pad_right_text(t_printf *arg)
{
	if (arg->op.fw > 1 && (arg->op.fl & FLAG_DASH))
		repeat_buf(&arg->buf, ' ', arg->op.fw - 1);
}

void	u_char(t_printf *arg)
{
	unsigned char	c;

	if (arg->op.length_mod & MOD_L)
		mb_char(arg);
	else
	{
		c = (unsigned char)va_arg(*(arg->ap), int);
		pad_left_text(arg);
		putc_buf(&arg->buf, c);
		pad_right_text(arg);
	}
}

void	string(t_printf *arg)
{
	ft_putendl("conversion found: %s");
}

void	mb_char(t_printf *arg)
{
	wchar_t		c;

	c = va_arg(*(arg->ap), wchar_t);
	if (c < 2048)
		arg->op.fw -= 1 * !(c < 127);
	else if (c < 65536)
		arg->op.fw -= 2;
	else
		arg->op.fw -= 3;
	pad_left_text(arg);
	putc_buf_unicode(&arg->buf, c);
	pad_right_text(arg);
}

void	mb_string(t_printf *arg)
{
	ft_putendl("conversion found: %S or %ls");
}

void	ptr_addr(t_printf *arg)
{
	ft_putendl("conversion found: %p");
}
