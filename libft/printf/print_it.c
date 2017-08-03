/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:40:11 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/10 20:14:34 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		len_print(t_magic *m)
{
	if (m->c == 'c' && m->buf[0] == 0)
		m->len = 1;
	else if (m->print[3] == '0' && m->p == 0)
		m->len = 0;
	else if (m->c == 's' || m->c == 'S')
	{
		if (m->p >= 0 && (m->p < m->len))
			m->len = m->p;
	}
}

void		print_it(t_magic *m)
{
	void	(*print_arr[5])(t_magic *);
	size_t	i;

	i = 0;
	print_arr[0] = print_0;
	print_arr[1] = print_1;
	print_arr[2] = print_2;
	print_arr[3] = print_3;
	print_arr[4] = print_0;
	len_print(m);
	m->w = A(m->w);
	while (i < 5)
	{
		if (m->print[i])
			(*print_arr[i])(m);
		i++;
	}
}
