/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_conversions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:30:53 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/18 09:54:20 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "integer_conversions.h"

char			get_base(char conv)
{
	if (conv == 'o' || conv == 'O')
		return (8);
	else if (conv == 'x' || conv == 'X')
		return (16);
	else
		return (10);
}

t_bool			get_signedness(char conv)
{
	if (conv == 'u'
			|| conv == 'U'
			|| conv == 'o'
			|| conv == 'O'
			|| conv == 'x'
			|| conv == 'X')
		return (true);
	else
		return (false);
}

intmax_t		get_cast(t_printf *arg)
{
	intmax_t	i;

	if (arg->op.length_mod & MOD_J)
		i = va_arg(*(arg->ap), intmax_t);
	else if (arg->op.length_mod & MOD_Z)
		i = va_arg(*(arg->ap), size_t);
	else if (arg->op.length_mod & MOD_LL)
		i = va_arg(*(arg->ap), long long int);
	else if (arg->op.length_mod & MOD_L)
		i = va_arg(*(arg->ap), long int);
	else if (arg->op.length_mod & MOD_HH)
		i = (char)va_arg(*(arg->ap), int);
	else if (arg->op.length_mod & MOD_H)
		i = (short int)va_arg(*(arg->ap), int);
	else
		i = va_arg(*(arg->ap), int);
	return (i);
}

uintmax_t		get_unsigned_cast(t_printf *arg)
{
	uintmax_t	i;

	if (arg->op.length_mod & MOD_J)
		i = va_arg(*(arg->ap), uintmax_t);
	else if (arg->op.length_mod & MOD_Z)
		i = va_arg(*(arg->ap), ssize_t);
	else if (arg->op.length_mod & MOD_LL)
		i = va_arg(*(arg->ap), unsigned long long int);
	else if (arg->op.length_mod & MOD_L)
		i = va_arg(*(arg->ap), unsigned long int);
	else if (arg->op.length_mod & MOD_HH)
		i = (unsigned char)va_arg(*(arg->ap), int);
	else if (arg->op.length_mod & MOD_H)
		i = (unsigned short int)va_arg(*(arg->ap), int);
	else
		i = va_arg(*(arg->ap), unsigned int);
	return (i);
}

t_integer_data	get_int_data(t_printf *a)
{
	t_integer_data	id;

	id.u = get_signedness(a->conv);
	id.num = (id.u) ? 0 : get_cast(a);
	id.unum = !(id.u) ? 0 : get_unsigned_cast(a);
	id.base = get_base(a->conv);
	id.digits = ft_count_digits_base((id.u ? id.unum : id.num), id.base);
	id.display_sign = (a->op.fl & (FLAG_PLUS | FLAG_SPACE))
		|| (!(id.u) && id.num < 0);
	id.diff_prec = a->op.prec - id.digits;
	id.alt = ((a->op.fl & FLAG_SHARP) && ((id.u ? id.unum : id.num) != 0)) *
			 ((id.base == 8 ? 1 : 0) + (id.base == 16 ? 2 : 0));
	id.caps = a->conv == 'X';
	id.to_pad = a->op.fw
		- (ft_max(id.digits, a->op.prec) + id.display_sign + id.alt);
	ft_putnbr_endl(id.alt);
	return (id);
}
