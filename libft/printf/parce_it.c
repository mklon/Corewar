/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 20:19:16 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/04 20:19:19 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			atoi_num(const char **fr)
{
	int		res;

	res = 0;
	if (**fr == '.')
		(*fr)++;
	while (FLAG_NUM(**fr))
	{
		res = res * 10 + ((**fr) - '0');
		(*fr)++;
	}
	--(*fr);
	return (res);
}

void		parce_if_digit(char fr, t_magic *m)
{
	if (FLAG_I(m->c) && (fr == '+' || fr == ' '))
	{
		if (fr == ' ' && m->print[1] == 0)
			m->print[1] = ' ';
		else if (fr == '+')
			m->print[1] = '+';
	}
	else if (fr == '#' && FLAG_X(m->c) && m->print[1] != '#')
		m->print[1] = '#';
}

void		clear_print(t_magic *m)
{
	if (m->w > 0)
		m->print[0] = ' ';
	else if (m->w < 0)
		m->print[4] = ' ';
	if (FLAG_DIGIT(m->c) || FLAG_P(m->c))
	{
		if (m->p > m->len)
			m->print[2] = '1';
		else if (m->print[2] == '0' && m->p >= 0)
			m->print[2] = 0;
	}
	if (m->print[2] == '0')
		m->print[0] = 0;
	if (m->print[4] == ' ')
	{
		m->print[0] = 0;
		if (m->print[2] == '0')
			m->print[2] = 0;
	}
	if (FLAG_PER(m->c))
		m->print[3] = '1';
	else if (FLAG_P(m->c))
		m->print[1] = '#';
}

void		get_precision(const char **fr, t_magic *m, va_list ap)
{
	if (FLAG_NUM(*(*fr + 1)))
		m->p = atoi_num(fr);
	else if (*(*fr + 1) == '*')
	{
		m->p = va_arg(ap, int);
		(*fr)++;
	}
	else
		m->p = 0;
}

void		parce_it(const char *fr, size_t l, t_magic *m, va_list ap)
{
	const char *end;

	end = fr + l;
	while (fr != end)
	{
		if (FLAG_NUM(*fr) && *fr != '0')
			m->w = atoi_num(&fr);
		else if (*fr == '.')
			get_precision(&fr, m, ap);
		else if (*fr == '*')
			m->w = va_arg(ap, int);
		else if ((*fr == ' ' || *fr == '+' || *fr == '#') && FLAG_XI(m->c))
			parce_if_digit(*fr, m);
		else if (*fr == '0' && m->print[2] != '0')
			m->print[2] = '0';
		else if (*fr == '-' && m->print[4] != ' ')
			m->print[4] = ' ';
		fr++;
	}
	clear_print(m);
}
