/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:56:17 by msymkany          #+#    #+#             */
/*   Updated: 2016/11/29 13:45:12 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)dst;
	if (len > 0)
	{
		if (src > dst)
			ft_memcpy(dst, src, len);
		if (src < dst)
		{
			while (len--)
				*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
		}
	}
	return (p);
}
