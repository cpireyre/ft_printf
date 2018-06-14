/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buftest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:41:30 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/14 10:11:42 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"

int		main(void)
{
	t_buf	buf;

	init_buf(&buf, 1);
	putc_buf(&buf, 0);
	putstr_buf(&buf, "this should be seamless or less");
	flush_buf(&buf);
	flush_buf(&buf);
	return (0);
}
