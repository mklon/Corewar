/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:07:05 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/16 17:43:32 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				len;
	char			*str;

	len = 0;
	len = ft_len_int(n);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	nbr = ft_isnegativ(n);
	while (len >= 0)
	{
		str[len--] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
