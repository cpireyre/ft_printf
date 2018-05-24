/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:16:46 by cpireyre          #+#    #+#             */
/*   Updated: 2018/05/19 08:03:30 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

int		main(int argc, char **argv)
{
	t_byte		options;

	if (argc == 2)
	{
		options = get_options(argv[1]);
		ft_print_options(options);
	}
	return (0);
}
