/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:00:45 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/02 15:05:52 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	s = (char*)src;
	d = (char*)dst;
	while (n--)
		d[n] = s[n];
	return (dst);
}
