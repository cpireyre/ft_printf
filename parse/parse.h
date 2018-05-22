/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:57:36 by cpireyre          #+#    #+#             */
/*   Updated: 2018/05/19 08:30:30 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"

typedef struct		s_options
{
	t_byte	flags;
	int	field_width;
	int	precision;
	t_byte	length_mod;
}			t_options;

t_byte			get_options(const char *spec);

#endif
