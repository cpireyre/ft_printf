/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:48:29 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/12 11:55:19 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_printf(t_printf *data, va_list *ap)
{
	data->ap = ap;
	data->buffer.pos = 0;
	data->buffer.filedesc = 1;
	data->written = 0;
}

static int	convert(t_printf *data, const char *format)
{
	size_t	j;

	j = 0;
	while (format[j] && !ft_strchr(CONVERSIONS, format[j]))
		j++;
	if (j)
		data->options = get_options(format + j);
	return (j);
}

int			ft_printf(const char *format, ...)
{
	t_printf	data;
	va_list		ap;
	size_t		i;

	va_start(ap, format);
	init_printf(&data, &ap);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i += convert(&data, format + i);
		else
		{
			putchar_buffer(&data.buffer, format[i]);
			data.written++;
		}
		i++;
	}
	return (data.written);
}
