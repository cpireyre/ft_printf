/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uUxX.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 10:53:08 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/18 10:56:19 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

void	u_dec(t_printf *arg)
{
	integer_conversion(arg);
}

void	l_u_dec(t_printf *arg)
{
	arg->op.length_mod |= MOD_L;
	integer_conversion(arg);
}

void	u_hex_low(t_printf *arg)
{
	integer_conversion(arg);
}

void	u_hex_upp(t_printf *arg)
{
	integer_conversion(arg);
}
