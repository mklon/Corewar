/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_castb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:42:35 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/23 13:43:15 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_castb(va_list ap, t_srt *lst)
{
	int	base;

	base = va_arg(ap, int);
	if (base <= 2)
		base = 2;
	else if (base >= 20)
		base = 20;
	return (ft_cast_unsigned(ap, lst, base));
}
