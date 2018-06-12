/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:22:38 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/12 08:26:02 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_byte		get_flags(const char *spec)
{
	size_t	i;
	t_byte	flags;

	i = 0;
	flags = 0;
	while (spec[i] && !ft_strchr(CONVERSIONS, spec[i]))
	{
		if (spec[i] == '#')
			flags = flags | (FLAG_SHARP);
		else if (spec[i] == '0')
			flags = flags | (FLAG_ZERO);
		else if (spec[i] == '-')
			flags = flags | (FLAG_DASH);
		else if (spec[i] == ' ')
			flags = flags | (FLAG_SPACE);
		else if (spec[i] == '+')
			flags = flags | (FLAG_PLUS);
		i++;
	}
	return (flags);
}

int			get_precision(const char *spec)
{
	size_t	i;

	i = 0;
	while (spec[i] && !ft_strchr(CONVERSIONS, spec[i]))
	{
		if (spec[i] == '.' && spec[i + 1])
			return (ft_atoi(spec + i + 1));
		i++;
	}
	return (0);
}

int			get_field_width(const char *spec)
{
	while (!ft_isdigit(*spec) || *spec == '0')
	{
		if (*spec == '.')
			return (1);
		spec++;
	}
	return (ft_atoi(spec));
}

t_byte		get_length_mod(const char *spec)
{
	size_t	i;
	t_byte	length_mod;

	i = 0;
	length_mod = 0;
	while (spec[i] && !ft_strchr(CONVERSIONS, spec[i]))
	{
		if (spec[i] == 'j')
			length_mod = length_mod | (MOD_J);
		else if (spec[i] == 'z')
			length_mod = length_mod | (MOD_Z);
		else if (spec[i] == 'h')
			length_mod = (length_mod & (MOD_H)) ? \
				(length_mod | (MOD_HH)) : (length_mod | (MOD_H));
		else if (spec[i] == 'l')
			length_mod = (length_mod & (MOD_L)) ? \
				(length_mod | (MOD_LL)) : (length_mod | (MOD_L));
		i++;
	}
	return (length_mod);
}

t_options			get_options(const char *spec)
{
	t_options	options;

	options.flags = get_flags(spec);
	options.field_width = get_field_width(spec);
	options.precision = get_precision(spec);
	options.length_mod = get_length_mod(spec);
	return (options);
}
