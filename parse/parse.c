/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:49:13 by cpireyre          #+#    #+#             */
/*   Updated: 2018/05/18 09:44:09 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static t_bool	is_flag(char c)
{
	return (c == '#' || 
			c == '0' || 
			c == '-' || 
			c == ' ' || 
			c == '+');
}

static int	get_flags(const char *spec)
{
	size_t	i;
	int		flags;

	i = 0;
	flags = 0;
	while (is_flag(spec[i]))
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

int		get_options(const char *spec)
{
	int		options;
	size_t	i;

	options = get_flags(spec);
	i = 0;
	while (is_flag(spec[i]))
		i++;
	return (options);
}
