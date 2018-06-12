/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:35:55 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/12 12:39:02 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include <unistd.h>

# define BUFF_SIZE		32768

typedef struct		s_buffer
{
	char	tab[BUFF_SIZE];
	size_t	pos;
	int		filedesc;
	int		written;
}					t_buffer;

void				flush_buffer(t_buffer *buf);
void				putchar_buffer(t_buffer *buf, char c);
void				putstr_buffer(t_buffer *buf, char *str);
void				init_buffer(t_buffer *buffer, int fd);

#endif
