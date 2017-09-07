/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:49:30 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/26 14:49:33 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *source, int ch)
{
	char	*s;

	s = (char*)source;
	while (*s)
		if (*s++ == (char)ch)
			return (--s);
	if (ch == 0)
		return (s);
	return (NULL);
}
