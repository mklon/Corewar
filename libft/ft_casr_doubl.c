/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casr_doubl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:13:39 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:19:06 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cast_f(va_list ap, t_srt *lst)
{
	long double	nb;
	char		*str;

	if (lst->size == 7 || lst->letar == 'F')
		nb = va_arg(ap, long double);
	nb = (long double)va_arg(ap, double);
	if (nb < 0)
	{
		lst->plus = '-';
		str = ft_str_double(-nb, lst);
	}
	else
		str = ft_str_double(nb, lst);
	str = ft_width(str, lst);
	if (lst->plus != '0')
		str = ft_plus(str, lst);
	return (str);
}

char	*ft_cast_e(va_list ap, t_srt *lst)
{
	double	nb;
	char	*str;

	if (lst->size == 7)
		nb = va_arg(ap, long double);
	else
		nb = va_arg(ap, double);
	if (nb < 0)
	{
		lst->plus = '-';
		str = ft_get_str_e(-nb, lst);
	}
	else
		str = ft_get_str_e(nb, lst);
	str = ft_width(str, lst);
	str = ft_plus(str, lst);
	return (str);
}

char	*ft_cast_el(va_list ap, t_srt *lst)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_cast_e(ap, lst);
	while (str[i])
	{
		str[i] = (char)ft_toupper(str[i]);
		i++;
	}
	return (str);
}
