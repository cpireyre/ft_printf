/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:16:46 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/09 14:33:19 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_options(t_options options)
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
	t_options		options;

	if (argc == 2)
	{
		while (*argv[1])
		{
			while (*argv[1] && *argv[1] != '%')
				argv[1]++;
			if (*argv[1] && *argv[1] == '%')
			{
				options = get_options(argv[1]);
				ft_putendl("\ncurrent option:");
				print_options(options);
			}
			argv[1]++;
		}
	}
	return (0);
}
