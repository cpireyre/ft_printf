/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 10:13:29 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/14 11:36:05 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"

void			flush_buf(t_buf *buf)
{
	if (buf->pos)
	{
		write(buf->filedesc, buf->tab, buf->pos);
		buf->pos = 0;
	}
}

void			putc_buf(t_buf *buf, char c)
{
	buf->tab[buf->pos] = c;
	buf->pos++;
	buf->written++;
	if (buf->pos == BUFF_SIZE)
		flush_buf(buf);
}

void			putstr_buf(t_buf *buf, char *str)
{
	while (*str)
	{
		putc_buf(buf, *str);
		str++;
	}
}

void			repeat_buf(t_buf *buf, char c, int num)
{
	while (num)
	{
		putc_buf(buf, c);
		num--;
	}
}
