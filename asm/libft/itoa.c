/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 17:03:46 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:26:42 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenint(long long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

long long int	isnegativ(long long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char			*itoa(long long int n)
{
	int				len;
	long long int	nbr;
	char			*str;

	nbr = isnegativ(n);
	len = ft_lenint(n);
	str = ft_strnew((size_t)len + 1);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (char)(nbr % 10 + '0');
		nbr = nbr / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
