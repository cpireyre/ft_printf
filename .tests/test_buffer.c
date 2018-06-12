/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buftest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:41:30 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/11 10:04:11 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

int		main(void)
{
	t_buffer	buf;

	init_buffer(&buf, 1);
	putchar_buffer(&buf, 0);
	putstr_buffer(&buf, "this should be seamless or less");
	flush_buffer(&buf);
	flush_buffer(&buf);
	return (0);
}
