/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbuffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:23:20 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/11 08:54:10 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

void		flush_buffer(t_buffer *buf)
{
	write(fd, buf->tab, buf->pos);
	buf->pos = 0;
}

void			putchar_buffer(t_buffer *buf, char c)
{
	buf->tab[buf->pos] = c;
	buf->pos++;
	if (buf->pos == BUFF_SIZE)
		flush_buffer(buf, fd);
}

void			putstr_buffer(t_buffer *buf, char *str)
{
	while (*str)
	{
		putchar_buffer(buf, *str, fd);
		str++;
	}
}
