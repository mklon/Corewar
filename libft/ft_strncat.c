/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:24:38 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/25 13:24:39 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *append, size_t n)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char*)dst;
	while (*d)
		d++;
	while (*append && i++ < n)
		*d++ = *(char*)append++;
	*d = '\0';
	return (dst);
}
