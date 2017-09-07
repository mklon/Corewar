/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:14:52 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/24 18:15:32 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*a2;

	i = 0;
	a1 = (unsigned char*)arr1;
	a2 = (unsigned char*)arr2;
	while (i++ < n && *a1 == *a2)
	{
		a1++;
		a2++;
	}
	if (--i == n)
		return (0);
	return ((int)(*a1 - *a2));
}
