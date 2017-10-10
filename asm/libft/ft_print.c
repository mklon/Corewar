/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:14:53 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:16:04 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_argdolar(va_list ap, va_list tmp, int len)
{
	va_copy(ap, tmp);
	while (--len)
		va_arg(ap, int);
}

char	*ft_getchar(t_srt *lst)
{
	char	*str;

	if (lst->chr != '0')
	{
		str = ft_strnew(1);
		str[0] = lst->chr;
		str[1] = '\0';
		str = ft_width(str, lst);
		return (str);
	}
	return (NULL);
}

int		ft_print(t_srt *lst, va_list ap, va_list tmp)
{
	char	*str;
	int		i;

	if (lst->dolar != 0)
		ft_argdolar(ap, tmp, lst->dolar);
	else if ((str = get_str(ap, lst)) != NULL
		|| (str = ft_getchar(lst)) != NULL)
	{
		ft_putstr_fd(str, lst->fd);
		i = (int)ft_strlen(str);
		ft_strdel(&str);
		return (i);
	}
	else if (lst->letar == 'c' || lst->letar == 'C')
		return (ft_cast_char(ap, lst));
	return (0);
}
