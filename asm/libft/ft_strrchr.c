/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:00:54 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/05 19:03:00 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	int		i;

	i = (int)ft_strlen(s);
	s1 = (char *)s;
	if (c == 0)
		return (s1 + i);
	while (i >= 0)
	{
		if (s1[i] == c)
			return (s1 + i);
		i--;
	}
	return (NULL);
}
