/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:39:25 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/18 10:11:47 by cpireyre         ###   ########.fr       */
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


void	u_char(t_printf *arg)
{
	ft_putendl("conversion found: %x");
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
