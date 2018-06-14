/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:16:46 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/14 13:31:05 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_byte		get_fl(const char *spec);
int			get_prec(const char *spec);
int			get_fw(const char *spec);
t_byte		get_length_mod(const char *spec);
t_op	get_op(const char *spec);


void	ft_assert(t_bool bool)
{
	if (bool)
		ft_putstr("\x1b[32m[OK]");
	else
		ft_putstr("\x1b[31m[error]");
}

int		main(void)
{
	ft_putendl("Testing fl...");
	ft_assert(get_fl("") == 0);
	ft_assert(get_fl("+-0 #") == (FLAG_PLUS | FLAG_SPACE | FLAG_DASH
				| FLAG_ZERO | FLAG_SHARP));
	ft_assert(get_fl("+") == FLAG_PLUS);

	ft_putendl("\x1b[0m\nTesting prec...");
	ft_assert(get_prec("") == 0);
	ft_assert(get_prec("555") == 0);
	ft_assert(get_prec(".555") == 555);
	ft_assert(get_prec("0") == 0);
	ft_assert(get_prec(".0") == 0);
	ft_assert(get_prec(".000001") == 1);
	ft_assert(get_prec("  1337  +0-- .2001") == 2001);
	ft_assert(get_prec("%//////////5555d %;;;;;;;.66S") == 0);
	ft_assert(get_prec("%//////////5555 %;;;;;;;.66S") == 66);
	return (0);
}
