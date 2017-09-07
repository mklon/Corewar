/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:34:00 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/24 16:34:02 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *source, size_t n)
{
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)source;
	if (s < d)
	{
		while ((int)n > 0)
		{
			n--;
			*(d + n) = *(s + n);
		}
	}
	else
		ft_memcpy(dst, source, n);
	return (dst);
}
