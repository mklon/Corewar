/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:47:00 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/13 16:47:06 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			get_hash(t_magic *m)
{
	int		hash;

	hash = 0;
	if (m->print[1])
	{
		if ((FLAG_X(m->c) && m->print[3] == '1') || FLAG_P(m->c))
			hash = (m->c == 'x' || m->c == 'X' || FLAG_P(m->c)) ? 2 : 1;
		else if ((m->c == 'o' || m->c == 'O') && m->len == 0)
			hash = 1;
		else if (m->print[1] != '#')
			hash = 1;
	}
	return (hash);
}

void		print_0(t_magic *m)
{
	int		hash;
	int		space;

	hash = get_hash(m);
	space = 0;
	if (FLAG_DIGIT(m->c) || FLAG_P(m->c))
	{
		if (m->p > m->len)
			space = m->w - m->p - ((m->c == 'o' || m->c == 'O') ? 0 : hash);
		else
			space = m->w - m->len - hash;
	}
	else if (FLAG_C(m->c) || FLAG_PER(m->c))
		space = m->w - m->len;
	while (space-- > 0)
		print_char(' ', m);
}

void		print_1(t_magic *m)
{
	if (FLAG_I(m->c))
		print_char(m->print[1], m);
	else if (FLAG_X(m->c) && m->print[3] == '1')
	{
		print_char('0', m);
		if (m->c == 'X')
			print_char('X', m);
		else if (m->c == 'x')
			print_char('x', m);
	}
	else if ((m->c == 'o' || m->c == 'O') && m->len == 0)
		print_char('0', m);
	else if (FLAG_P(m->c))
	{
		print_char('0', m);
		print_char('x', m);
	}
}

void		print_2(t_magic *m)
{
	int		hash;
	int		null;

	hash = get_hash(m);
	null = 0;
	if (m->print[2] == '1')
		null = m->p - m->len - ((m->c == 'o' || m->c == 'O') ? hash : 0);
	else if (m->print[2] == '0')
		null = m->w - m->len - hash;
	while (null-- > 0)
		print_char('0', m);
}

void		print_3(t_magic *m)
{
	if ((m->c == 'c' || m->c == 'C') && m->buf[0] == 0)
	{
		write(1, "\0", 1);
		(m->r)++;
	}
	else
		print_str(m, m->len);
}
