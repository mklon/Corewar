/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:09:05 by amovchan          #+#    #+#             */
/*   Updated: 2017/10/12 21:20:52 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_srt	*inicial_struct(t_srt *lst)
{
	lst->letar = '0';
	lst->zero_or_minus = '0';
	lst->space = '0';
	lst->plus = '0';
	lst->hesh = 0;
	lst->size = 0;
	lst->accur = -1;
	lst->width = -1;
	lst->rs = 0;
	lst->fd = 1;
	lst->ap = 0;
	lst->dolar = 0;
	lst->color = 0;
	lst->chr = '0';
	return (lst);
}

int		atoidig(const char *str, int *i)
{
	int	nb;

	nb = 0;
	while (str[(*i)] >= 48 && str[(*i)] <= 57)
	{
		nb *= 10;
		nb += ((int)str[(*i)] - 48);
		(*i)++;
	}
	(*i)--;
	return (nb);
}

void	ft_formate(const char *str, int *i, t_srt *lst)
{
	ft_specifiers(str, i, lst);
	if (flag_format(str[(*i)], lst) == 1)
		;
	else if (ft_isdigit(str[(*i)]) == 1)
		ft_width_or_dolar(str, i, lst);
	else if (flag_format(str[(*i)], lst) == 1)
		;
	else if (str[(*i)] == '#')
		lst->hesh = 1;
	else if (str[(*i)] == '\'')
		lst->ap = 1;
}

t_srt	*ft_print_format(t_srt *lst, const char *str, int *i, va_list ap)
{
	while (str[++(*i)] && lst->letar == '0')
	{
		ft_formate(str, i, lst);
		if (str[(*i)] == '*' && (lst->width = -1))
			lst->width = va_arg(ap, int);
		else if (add_dot(str, i, lst, ap) == 1)
			;
		else if (str[(*i)] == '{')
			ft_color(str, i, ap, lst);
		else if (tayp(str[(*i)]) == 1)
		{
			lst->letar = str[(*i)];
			break ;
		}
		else if ((ft_strchr("1234567890'#+-.* Llhjz$", str[(*i)]) == NULL))
		{
			lst->chr = str[(*i)];
			return (lst);
		}
	}
	if (str[(*i)] == '\0')
		(*i)--;
	return (lst);
}

int		ft_format(const char *format, va_list ap)
{
	t_srt	*list;
	int		i;
	int		res;
	va_list	tmp;

	i = -1;
	res = 0;
	list = (t_srt*)malloc(sizeof(t_srt));
	va_copy(tmp, ap);
	list->fd = 1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			list = inicial_struct(list);
			list = ft_print_format(list, format, &i, ap);
			res += ft_print(list, ap, tmp);
			ft_argn(res, ap, list);
		}
		else
			res += ft_printformat(format, &i, list, ap);
	}
	free(list);
	return (res);
}
