/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:53:13 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/14 11:17:15 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"

int		main(void)
{
	t_printf	mess;
	void 		(*conv)(t_printf *);

	conv = get_conversion('c');
	conv(&mess);
	conv = get_conversion('u');
	conv(&mess);
	conv = get_conversion('x');
	conv(&mess);
	conv = get_conversion('X');
	conv(&mess);
	conv = get_conversion('D');
	conv(&mess);
	conv = get_conversion('O');
	conv(&mess);
	conv = get_conversion('U');
	conv(&mess);
	conv = get_conversion('s');
	conv(&mess);
	conv = get_conversion('C');
	conv(&mess);
	conv = get_conversion('S');
	conv(&mess);
	conv = get_conversion('p');
	conv(&mess);
	return (0);
}
