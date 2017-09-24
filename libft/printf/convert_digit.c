/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:29:58 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/13 16:30:08 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		get_base(char c)
{
	int		b;

	b = 0;
	if (FLAG_U(c))
		b = (c == 'b') ? 2 : 10;
	else if (FLAG_X(c))
		b = ((c == 'o' || c == 'O') ? 8 : 16);
	return (b);
}

void	itoa_int(intmax_t value, t_magic *m)
{
	size_t		l;
	uintmax_t	v;
	char		*hex;

	hex = "0123456789";
	l = 1;
	v = A(value);
	m->print[3] = (value == 0) ? '0' : '1';
	if (value < 0)
		m->print[1] = '-';
	while (v /= BASE)
		l++;
	if (!(m->buf = (char *)malloc(sizeof(char) * (l + 1))))
		return ;
	m->buf[l--] = 0;
	if (value == 0)
		m->buf[l] = '0';
	v = A(value);
	while (v)
	{
		m->buf[l--] = hex[v % BASE];
		v /= BASE;
	}
}

void	itoa_base(uintmax_t value, int base, t_magic *m)
{
	size_t		l;
	uintmax_t	v;
	char		*hex;

	m->print[3] = '1';
	hex = (m->c == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	v = value;
	l = 1;
	while (v /= base)
		l++;
	if (!(m->buf = (char *)malloc(sizeof(char) * (l + 1))))
		return ;
	m->buf[l--] = 0;
	if (value == 0)
	{
		m->buf[l] = '0';
		m->print[3] = '0';
	}
	while (value)
	{
		m->buf[l--] = hex[value % base];
		value /= base;
	}
}
