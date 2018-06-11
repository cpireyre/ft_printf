/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:27:21 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/11 08:01:43 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

# include "ft_printf.h"
# include "wchar.h"

/*
** d + i, c. int conversions.
*/

int		signed_dec(t_printf *arg);
int		u_char(t_printf *arg);

/*
 ** o, u, x, X. unsigned int conversions.
*/

int		u_octal(t_printf *arg);
int		u_dec(t_printf *arg);
int		u_hex_low(t_printf *arg);
int		u_hex_upp(t_printf *arg);

/*
** D, O, U. long int conversions.
** I will use these to handle ld, lo, lu, etc. by casting
** arg to long int and calling the following functions. Maybe.
*/

int		l_signed_dec(t_printf *arg);
int		l_u_octal(t_printf *arg);
int		l_u_dec(t_printf *arg);

/*
**  s. const char * conversion.
*/

int		string(t_printf *arg);

/*
** C, S. wint_t and wchar_t * conversions.
*/

int		mb_char(t_printf *arg);
int		mb_string(t_printf *arg);

/*
** p. pointer conversion. similar to %#x.
*/

int		ptr_addr(t_printf *arg);

#endif
