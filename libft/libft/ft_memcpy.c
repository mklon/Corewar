/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:32:59 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/08 16:55:49 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ptr;
	unsigned char *ptrs;

	ptr = dst;
	ptrs = (unsigned char *)src;
	while (n--)
		*ptr++ = *ptrs++;
	return (dst);
}
