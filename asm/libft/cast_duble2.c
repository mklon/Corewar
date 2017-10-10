/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_duble2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:44:21 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/17 19:06:33 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cast_gi(va_list ap, t_srt *lst)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_str_g(ap, lst);
	while (str[i])
	{
		str[i] = (char)ft_toupper(str[i]);
		i++;
	}
	return (str);
}

char	*ft_cast_a(va_list ap, t_srt *lst)
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
		str = ft_getstr_a(-nb, lst);
	}
	else
		str = ft_getstr_a(nb, lst);
	str = ft_width(str, lst);
	str = ft_plus(str, lst);
	return (str);
}

char	*ft_cast_al(va_list ap, t_srt *lst)
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
		str = ft_getstr_a2(-nb, lst);
	}
	else
		str = ft_getstr_a2(nb, lst);
	str = ft_width(str, lst);
	str = ft_plus(str, lst);
	return (str);
}
