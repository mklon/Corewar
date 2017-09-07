/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:42:56 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/04 18:44:03 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	n;
	char	*d;
	char	*s;

	d = dst;
	s = (char *)src;
	n = size;
	while (n-- && *d)
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (!n)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
