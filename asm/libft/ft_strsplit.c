/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:25:03 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/16 19:15:38 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	char	*s1;
	char	**s2;

	if (!s || !(res = malloc(sizeof(char*) * (ft_nb_words(s, c) + 1))))
		return (NULL);
	s2 = res;
	while (*s)
	{
		while (*s == c && *s && s++)
			;
		if (*s)
		{
			if (!(s1 = malloc(sizeof(char) * ft_ln_w(s, c) + 1)))
				return (NULL);
			*res = s1;
			while (*s != c && *s && (*s1++ = *s++))
				;
			*s1 = '\0';
			res++;
		}
	}
	*res = NULL;
	return (s2);
}
