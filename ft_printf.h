/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:57:36 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/09 14:21:17 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define CONVERSIONS "DdiOoUuXxCcSs"

typedef struct		s_options
{
	t_byte	flags;
	int		field_width;
	int		precision;
	t_byte	length_mod;
}					t_options;

t_options			get_options(const char *spec);

#endif
