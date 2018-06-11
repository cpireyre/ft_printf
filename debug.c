/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:03:27 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/11 13:12:14 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_print_options(t_options options)
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

void	debug_print_printf(t_printf *mess)
{
	debug_print_options(mess->options);
	ft_putendl("\nBuffer: ");
	flush_buffer(mess->buffer);
	ft_putstr("\nCharacters written so far: ");
	ft_putnbr_endl(mess->written);
}
