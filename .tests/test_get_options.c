/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:16:46 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/12 08:41:16 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_byte		get_flags(const char *spec);
int			get_precision(const char *spec);
int			get_field_width(const char *spec);
t_byte		get_length_mod(const char *spec);
t_options	get_options(const char *spec);

void		print_options(t_options options)
{
	ft_putstr("Flags: ");
	ft_print_bits(options.flags);
	ft_putstr("\nField width: ");
	ft_putnbr_endl(options.field_width);
	ft_putstr("Precision: ");
	ft_putnbr_endl(options.precision);
	ft_putstr("Length modifier: ");
	ft_print_bits(options.length_mod);
}

void	ft_assert(t_bool bool)
{
	if (bool)
		ft_putstr("\x1b[32m[OK]");
	else
		ft_putstr("\x1b[31m[error]");
}

int		main(void)
{
	ft_putendl("Testing flags...");
	ft_assert(get_flags("") == 0);
	ft_assert(get_flags("+-0 #") == (FLAG_PLUS | FLAG_SPACE | FLAG_DASH
				| FLAG_ZERO | FLAG_SHARP));
	ft_assert(get_flags("+") == FLAG_PLUS);

	ft_putendl("\x1b[0m\nTesting precision...");
	ft_assert(get_precision("") == 0);
	ft_assert(get_precision("555") == 0);
	ft_assert(get_precision(".555") == 555);
	ft_assert(get_precision("0") == 0);
	ft_assert(get_precision(".0") == 0);
	ft_assert(get_precision(".000001") == 1);
	ft_assert(get_precision("  1337  +0-- .2001") == 2001);
	ft_assert(get_precision("%//////////5555d %;;;;;;;.66S") == 0);
	ft_assert(get_precision("%//////////5555 %;;;;;;;.66S") == 66);
	return (0);
}
