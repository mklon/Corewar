/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:38:02 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/08 16:56:16 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char *ptrs;

	ptr = dst;
	ptrs = (unsigned char *)src;
	while (n--)
	{
		*ptr = *ptrs;
		if (*ptrs == (unsigned char)c)
			return (++ptr);
		ptr++;
		ptrs++;
	}
	return ((void *)NULL);
}
