/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:59:26 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/05 13:04:47 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		if (*(unsigned char*)src == (unsigned char)c)
			return (dst + 1);
		return (ft_memccpy((dst + 1), (src + 1), c, n));
	}
	return (NULL);
}
