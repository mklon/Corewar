/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:15:25 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/05 13:23:27 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t i;

	i = 0;
	while (dst[i] && i < size)
		i++;
	len = i;
	while (src[i - len] && i < size - 1)
	{
		dst[i] = src[i - len];
		i++;
	}
	if (len < size)
		dst[i] = '\0';
	return (len + ft_strlen(src));
}
