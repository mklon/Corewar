/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:04:05 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/26 15:04:07 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *source, size_t n)
{
	size_t	i;

	i = 0;
	while (*source && i < n)
	{
		dst[i] = *source;
		source++;
		i++;
	}
	while (i < n)
		dst[i++] = '\0';
	return (dst);
}
