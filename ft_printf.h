/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:51:14 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/12 12:54:52 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "buffer.h"
# include <stdarg.h>

# define DEBUG 1

# define CONVERSIONS	"DdiOoUuXxCcSsp"
# define NBR_CONVERSIONS 14

# define FLAG_DASH	 	(1)
# define FLAG_ZERO		(1 << 1)
# define FLAG_SHARP		(1 << 2)
# define FLAG_SPACE		(1 << 3)
# define FLAG_PLUS		(1 << 4)

# define MOD_J			(1)
# define MOD_Z			(1 << 1)
# define MOD_H			(1 << 2)
# define MOD_HH			(1 << 3)
# define MOD_L			(1 << 4)
# define MOD_LL			(1 << 5)

typedef struct		s_options
{
	t_byte	flags;
	int		field_width;
	int		precision;
	t_byte	length_mod;
}					t_options;

typedef struct		s_printf
{
	va_list		*ap;
	t_options	options;
	t_buffer	buffer;
}					t_printf;

t_options			get_options(const char *spec);
void 				(*get_conversion(const char arg))(t_printf *);
int					ft_printf(const char *format, ...);

#endif
