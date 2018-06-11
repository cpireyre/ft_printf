/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buftest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:41:30 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/11 08:58:42 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

int		main(void)
{
	t_buffer	buf;

	buf.pos = 0;
	buf.filedesc = 1;
	putchar_buffer(&buf, 0);
	putstr_buffer(&buf, "this should be seamless or less");
	flush_buffer(&buf);
	flush_buffer(&buf);
	return (0);
}
