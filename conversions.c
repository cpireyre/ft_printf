/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:39:25 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/20 13:57:44 by cpireyre         ###   ########.fr       */
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

void	pad_left_text(t_printf *arg, int to_pad)
{
	if ((arg->op.fw - to_pad) > 1 && !(arg->op.fl & FLAG_DASH))
		repeat_buf(&arg->buf, ' ', arg->op.fw - to_pad - 1);
}

void	pad_right_text(t_printf *arg, int to_pad)
{
	if ((arg->op.fw - to_pad) > 1 && (arg->op.fl & FLAG_DASH))
		repeat_buf(&arg->buf, ' ', arg->op.fw - to_pad - 1);
}

int		get_to_pad(wchar_t uchar)
{
	if (uchar < 128)
		return (0);
	else if (uchar < 2048)
		return (1);
	else if (uchar < 1048576)
		return (2);
	else
		return (3);
}

void	u_char(t_printf *arg)
{
	unsigned char	c;

	if (arg->op.length_mod & MOD_L)
		mb_char(arg);
	else
	{
		c = (unsigned char)va_arg(*(arg->ap), int);
		pad_left_text(arg, 1);
		putc_buf(&arg->buf, c);
		pad_right_text(arg, 1);
	}
}

void	string(t_printf *arg)
{
	ft_putendl("conversion found: %s");
}

void	mb_char(t_printf *arg)
{
	wchar_t		c;
	int			to_pad;

	c = va_arg(*(arg->ap), wchar_t);
	to_pad = get_to_pad(c);
	pad_left_text(arg, to_pad);
	putc_buf_unicode(&arg->buf, c);
	pad_right_text(arg, to_pad);
}

void	mb_string(t_printf *arg)
{
	ft_putendl("conversion found: %S or %ls");
}

void	ptr_addr(t_printf *arg)
{
	ft_putendl("conversion found: %p");
}
