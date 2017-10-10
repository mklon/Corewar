/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:17:19 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/16 14:37:15 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s1;
	char			*s2;

	if (s && f)
	{
		if ((s1 = ft_strnew(ft_strlen(s))))
		{
			s2 = s1;
			i = 0;
			while (*s)
			{
				*s1++ = (*f)(i, *s);
				s++;
				i++;
			}
			return (s2);
		}
	}
	return (NULL);
}
