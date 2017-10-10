/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:54:46 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/16 17:36:37 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;

	if (!s || !(s1 = (char *)malloc(len + 1))
			|| (start > (unsigned int)ft_strlen(s)))
		return (NULL);
	else
	{
		s1 = ft_strncpy(s1, (s + start), len);
		s1[len] = '\0';
	}
	return (s1);
}
