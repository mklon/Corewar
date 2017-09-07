/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:27:10 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/26 15:27:11 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *source, int ch)
{
	char	*s;
	size_t	i;

	s = (char*)source;
	i = ft_strlen(s);
	while (i != 0 && s[i] != (char)ch)
		i--;
	if (s[i] == (char)ch)
		return (&s[i]);
	return (NULL);
}
