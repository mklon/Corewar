/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:30:57 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/13 16:31:00 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				size_wchar(wchar_t w)
{
	if (w <= 127)
		return (1);
	else if (w <= 2047)
		return (2);
	else if (w <= 65535)
		return (3);
	else if (w <= 2097151)
		return (4);
	return (0);
}

char			*wchar_conv(wchar_t w)
{
	int		size;
	char	*buf;

	size = size_wchar(w);
	buf = ft_strnew(size);
	if (size == 1)
		buf[0] = (char)w;
	else
		buf[0] = (w >> (6 * (size - 1))) | (240 << (4 - size));
	while (--size > 0)
	{
		buf[size] = (w & 63) | 128;
		w = w >> 6;
	}
	return (buf);
}

void			wstr_join(wchar_t *arg, t_magic *m)
{
	char	*tmp;
	char	*w_char;

	if (!m->buf)
		m->buf = wchar_conv(*(arg));
	else
	{
		tmp = ft_strdup(m->buf);
		ft_strdel(&m->buf);
		w_char = wchar_conv(*arg);
		m->buf = ft_strjoin(tmp, w_char);
		ft_strdel(&w_char);
		ft_strdel(&tmp);
	}
}

void			wstr_conv(wchar_t *arg, t_magic *m)
{
	int		i;

	i = 0;
	m->print[3] = (!arg) ? '0' : '1';
	if (!arg)
		m->buf = ft_strdup("(null)");
	else if (m->p >= 0)
	{
		while (*arg && ((i += size_wchar(*arg)) <= m->p))
		{
			wstr_join(arg, m);
			arg++;
		}
	}
	else
	{
		while (*arg)
		{
			wstr_join(arg, m);
			arg++;
		}
	}
	if (!m->buf)
		m->buf = ft_strdup("");
}
