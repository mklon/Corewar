/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_dig2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:56:05 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 23:10:45 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_castnegativ(intmax_t nbr, t_srt *lst)
{
	char	*str;

	if (nbr < 0)
	{
		str = ft_itoa_base(-nbr, 10);
		if (lst->width == -1)
			lst->zero_or_minus = '0';
		lst->plus = '-';
	}
	else
		str = itoa(nbr);
	return (str);
}
