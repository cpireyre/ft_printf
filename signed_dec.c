/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:16:02 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/13 12:36:04 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		signed_dec(t_printf *arg)
{
	int		i;
	int		digits;

	i = va_arg(*(arg->ap), int);
	digits = ft_count_digits_base(i, 10) + (i < 0 ? 1 : 0);
	if ((arg->options.field_width - digits) > 0 
			&& arg->options.flags & FLAG_ZERO
			&& !(arg->options.flags & FLAG_DASH)
			&& !arg->options.precision)
		repeat_buffer(&arg->buffer, '0', arg->options.field_width - digits);
	ft_putnbr(i);
}
