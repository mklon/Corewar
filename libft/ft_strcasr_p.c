/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasr_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:23:43 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:24:58 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcast_p(va_list ap, t_srt *lst)
{
	char		*str;
	uintmax_t	nbr;
	char		*src;

	src = ft_strdup("0x");
	nbr = (uintmax_t)va_arg(ap, long long int);
	str = ft_itoa_base(nbr, 16);
	str = ft_accur_digits(str, lst);
	if ((int)ft_strlen(str) < lst->width
		&& nbr == 0 && lst->zero_or_minus == '1')
		lst->width -= 2;
	if (lst->zero_or_minus != '1')
	{
		str = ft_strjoin(src, str);
		str = ft_width(str, lst);
	}
	else
	{
		str = ft_width(str, lst);
		str = ft_strjoin(src, str);
	}
	return (str);
}
