/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:14:07 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/16 14:34:06 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	char	*s1;

	if (s && f)
	{
		if ((s2 = ft_strnew(ft_strlen(s))))
		{
			s1 = s2;
			while (*s)
			{
				*s2++ = (*f)(*s);
				s++;
			}
			return (s1);
		}
	}
	return (NULL);
}
