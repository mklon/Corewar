/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:17:23 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 20:53:25 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printformat(const char *str, int *i, t_srt *lst, va_list ap)
{
	int res;

	res = 0;
	if (str[(*i)] == '{')
	{
		ft_color(str, i, ap, lst);
		if (lst->color != 1)
		{
			if (lst->fd == 1)
			{
				ft_putchar_fd(str[(*i)], lst->fd);
				res++;
			}
		}
	}
	else
	{
		ft_putchar_fd(str[(*i)], lst->fd);
		res++;
	}
	return (res);
}

void	ft_width_or_dolar(const char *str, int *i, t_srt *lst)
{
	int		len;

	len = atoidig(str, i);
	if (str[(*i) + 1] == '$')
		lst->dolar = len;
	else if (len > 0 || lst->width == -1)
		lst->width = len;
}
