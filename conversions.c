/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:39:25 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/17 10:57:29 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

void	(*get_conversion(const char arg))(t_printf *)
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

void	u_dec(t_printf *arg)
{
	ft_putendl("conversion found: %c");
}

void	l_u_dec(t_printf *arg)
{
	ft_putendl("conversion found: %c");
}

void	u_char(t_printf *arg)
{
	ft_putendl("conversion found: %x");
}

void	u_hex_low(t_printf *arg)
{
	ft_putendl("conversion found: %x");
}

void	u_hex_upp(t_printf *arg)
{
	ft_putendl("conversion found: %X");
}

void	l_u_octal(t_printf *arg)
{
	ft_putendl("conversion found: %O or %lo");
}

void	string(t_printf *arg)
{
	ft_putendl("conversion found: %s");
}

void	mb_char(t_printf *arg)
{
	ft_putendl("conversion found: %C or %lc");
}

void	mb_string(t_printf *arg)
{
	ft_putendl("conversion found: %S or %ls");
}

void	ptr_addr(t_printf *arg)
{
	ft_putendl("conversion found: %p");
}
