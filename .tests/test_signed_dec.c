/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signed_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 08:15:57 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/18 09:56:41 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("^.^/%#25.5hho^.^/\n", 2000396176);
	printf("^.^/%#25.5hho^.^/\n", 2000396176);
	ft_printf("%hho\n", 2000396176);
	return (0);
}
