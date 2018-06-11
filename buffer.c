/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbuffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:23:20 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/11 10:03:27 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

void			flush_buffer(t_buffer *buf)
{
	if (buf->pos)
	{
		write(buf->filedesc, buf->tab, buf->pos);
		buf->pos = 0;
	}
}

void			putchar_buffer(t_buffer *buf, char c)
{
	buf->tab[buf->pos] = c;
	buf->pos++;
	if (buf->pos == BUFF_SIZE)
		flush_buffer(buf);
}

void			putstr_buffer(t_buffer *buf, char *str)
{
	while (*str)
	{
		putchar_buffer(buf, *str);
		str++;
	}
}

void			init_buffer(t_buffer *buffer, int fd)
{
	buffer->pos = 0;
	buffer->filedesc = fd;
}
