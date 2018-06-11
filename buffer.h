/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:35:55 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/11 08:50:15 by cpireyre         ###   ########.fr       */
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
}					t_buffer;

void				flush_buffer(t_buffer *buf, int fd);
void				putchar_buffer(t_buffer *buf, char c, int fd);
void				putstr_buffer(t_buffer *buf, char *str, int fd);

#endif
