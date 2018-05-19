/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:16:46 by cpireyre          #+#    #+#             */
/*   Updated: 2018/05/19 08:03:30 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		main(int argc, char **argv)
{
	t_byte		options;

	if (argc == 2)
	{
		options = get_options(argv[1]);
		ft_print_bits(options);
	}
	return (0);
}
