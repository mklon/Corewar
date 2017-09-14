/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:06:50 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/01 21:32:06 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_magic		*get_it(const char **fr, va_list ap, t_magic *m)
{
	const char	*s;
	char		fl;

	fl = -1;
	s = *fr;
	*fr = skip_flags(*fr, &fl);
	if (!**fr)
		return (m);
	if (!m)
		m = init_struct();
	clear_struct(m, fl);
	(m)->c = ((FLAG_CON(**fr) || FLAG_P(**fr)) ? **fr : '%');
	parce_it(s, *fr - s, m, ap);
	if (FLAG_CON(**fr) || FLAG_P(**fr))
		conv_arg(ap, m);
	else
		(m)->buf = ft_strsub(*fr, 0, 1);
	print_it(m);
	(*fr)++;
	return (m);
}

int			ft_printf(const char *format, ...)
{
	const char	*fr;
	int			ret;
	va_list		ap;
	t_magic		*m;

	m = NULL;
	ret = 0;
	fr = format;
	va_start(ap, format);
	while (*fr)
	{
		if (*fr != '%')
			fr = put_txt(fr, &ret);
		else if (*fr == '%' && *(++fr))
		{
			m = get_it(&fr, ap, m);
			if (m)
				ret += m->r;
		}
	}
	if (m)
		del_struct(&m);
	va_end(ap);
	return (ret);
}
