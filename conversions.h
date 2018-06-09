/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:27:21 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/09 12:53:57 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

# include "parse.h"
# include "wchar.h"

/*
** d + i, c. int conversions.
*/

char	*signed_dec(int arg, t_options options);
t_byte	u_char(int arg, t_options options);

/*
 ** o, u, x + X. unsigned int conversions.
*/

char	*u_octal(t_uint arg, t_options options);
char	*u_dec(t_uint arg, t_options options);
char	*u_hex(t_uint arg, t_options options, t_bool upcase);

/*
** D, O, U. long int conversions.
** I will use these to handle ld, lo, lu, etc. by casting
** arg to long int and calling the following functions. Maybe.
*/

char	*l_signed_dec(long int arg, t_options options);
char	*l_u_octal(long int arg, t_options options);
char	*l_u_dec(long int arg, t_options options, t_bool upcase);

/*
**  s. const char * conversion.
*/

char	*string(const char *arg, t_options options);

/*
** C, S. wint_t and wchar_t * conversions.
*/

char	*mb_char(wint_t arg, t_options options);
char	*mb_string(const wchar_t *arg, t_options options);

/*
** p. pointer conversion. similar to %#x.
*/

char	*ptr_addr(void *arg, t_options options);

#endif
