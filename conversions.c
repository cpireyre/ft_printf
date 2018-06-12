/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:39:25 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/12 11:55:10 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

void (*get_conversion(const char arg))(t_printf *)
{
	size_t	i;

	i = 0;
	while (i < NBR_CONVERSIONS)
	{
		if (g_conversions[i].letter == arg)
			return (g_conversions[i].conversion);
		i++;
	}
	if (DEBUG)
		ft_putendl("Error: couldn't find conversion function.");
	return (NULL);
}

void	signed_dec(t_printf *arg)
{
	ft_putendl("%d or %i");
}

void	u_char(t_printf *arg)
{
	ft_putendl("%c");
}

void	u_octal(t_printf *arg)
{
	ft_putendl("%o");
}

void	u_dec(t_printf *arg)
{
	ft_putendl("%u");
}

void	u_hex_low(t_printf *arg)
{
	ft_putendl("%x");
}

void	u_hex_upp(t_printf *arg)
{
	ft_putendl("%X");
}

void	l_signed_dec(t_printf *arg)
{
	ft_putendl("%D or %ld");
}

void	l_u_octal(t_printf *arg)
{
	ft_putendl("%O or %lo");
}

void	l_u_dec(t_printf *arg)
{
	ft_putendl("%U or %lu");
}

void	string(t_printf *arg)
{
	ft_putendl("%s");
}

void	mb_char(t_printf *arg)
{
	ft_putendl("%C or %lc");
}

void	mb_string(t_printf *arg)
{
	ft_putendl("%S or %ls");
}

void	ptr_addr(t_printf *arg)
{
	ft_putendl("%p");
}

