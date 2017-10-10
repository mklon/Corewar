/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_floar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:07:17 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/17 19:09:06 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_ceil(long double nbr)
{
	long double	i;

	i = (long long)nbr;
	if (nbr <= i)
		return (i);
	return (i + 1);
}

long double		ft_floor(long double nbr)
{
	long double	i;

	i = (long long)nbr;
	if (nbr >= i)
		return (i);
	return (i - 1);
}

long double		ft_r_nbr(long double nbr)
{
	if (nbr - ft_floor(nbr) == 0.5 && (long long)ft_floor(nbr) % 2 == 0)
		return (ft_floor(nbr));
	else if (ft_ceil(nbr) - nbr == 0.5)
		return (ft_ceil(nbr));
	return ((nbr - ft_floor(nbr) >= 0.5 ? ft_ceil(nbr) : ft_floor(nbr)));
}
