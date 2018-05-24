/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:49:13 by cpireyre          #+#    #+#             */
/*   Updated: 2018/05/19 07:51:58 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static t_byte	get_flags(const char *spec)
{
	size_t	i;
	t_byte	flags;

	i = 0;
	flags = 0;
	while (spec[i])
	{
		if (spec[i] == '#')
			flags = flags | 1;
		else if (spec[i] == '0')
			flags = flags | 1 << 1;
		else if (spec[i] == '-')
			flags = flags | 1 << 2;
		else if (spec[i] == ' ')
			flags = flags | 1 << 3;
		else if (spec[i] == '+')
			flags = flags | 1 << 4;
		i++;
	}
	return (flags);
}

static int	get_precision(const char *spec)
{
	while (*spec)
		spec++;
	spec--;
	while (*spec != '.')
		spec--;
	spec++;
	return (ft_atoi(spec));
}

static int	get_field_width(const char *spec)
{
	while (!ft_isdigit(*spec))
		spec++;
	return (ft_atoi(spec));
}

t_options	get_options(const char *spec)
{
	t_options	options;

	options.flags = get_flags(spec);
	options.field_width = get_field_width(spec);
	options.precision = get_precision(spec);
	return (options);
}
