/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_cast_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:27:28 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/20 20:29:04 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		conv_arg(va_list ap, t_magic *m)
{
	void	*arg;

	arg = va_arg(ap, void *);
	if (FLAG_I(m->c))
		conv_signed(arg, m);
	else if (FLAG_U(m->c) || FLAG_X(m->c))
		conv_unsigned(arg, m);
	else if (FLAG_C(m->c) || FLAG_P(m->c))
		conv_char(arg, m);
	m->len = (int)ft_strlen(m->buf);
}

void		conv_unsigned(void *arg, t_magic *m)
{
	int		base;

	base = get_base(m->c);
	if ((m->c == 'U' || m->c == 'O') && (m->mod < 'l'))
		m->mod = 'l';
	if (m->mod == 'f')
		itoa_base((unsigned char)arg, base, m);
	else if (m->mod == 'h')
		itoa_base((unsigned short int)arg, base, m);
	else if (m->mod == 'l')
		itoa_base((unsigned long int)arg, base, m);
	else if (m->mod == 'm')
		itoa_base((unsigned long long int)arg, base, m);
	else if (m->mod == 'z')
		itoa_base((size_t)arg, base, m);
	else if (m->mod == 'j')
		itoa_base((uintmax_t)arg, base, m);
	else
		itoa_base((unsigned int)arg, base, m);
}

void		conv_signed(void *arg, t_magic *m)
{
	if (m->c == 'D' && m->mod < 'l')
		m->mod = 'l';
	if (m->mod == 'f')
		itoa_int((char)arg, m);
	else if (m->mod == 'h')
		itoa_int((short int)arg, m);
	else if (m->mod == 'l')
		itoa_int((long int)arg, m);
	else if (m->mod == 'm')
		itoa_int((long long int)arg, m);
	else if (m->mod == 'z')
		itoa_int((size_t)arg, m);
	else if (m->mod == 'j')
		itoa_int((intmax_t)arg, m);
	else
		itoa_int((int)arg, m);
}

void		conv_char(void *arg, t_magic *m)
{
	if (m->c == 'c' && m->mod != 'l')
	{
		m->buf = ft_strnew(1);
		m->buf[0] = (char)arg;
		m->print[3] = '1';
	}
	else if (m->c == 's' && m->mod != 'l')
	{
		if ((char *)arg)
			m->buf = ft_strdup((char *)arg);
		else
			m->buf = ft_strdup("(null)");
		m->print[3] = '1';
	}
	else if (m->c == 'c' || m->c == 'C')
	{
		m->buf = wchar_conv((wchar_t)arg);
		m->print[3] = '1';
	}
	else if (m->c == 's' || m->c == 'S')
		wstr_conv((wchar_t *)arg, m);
	else if (m->c == 'p')
		itoa_base((unsigned long int)arg, 16, m);
}
