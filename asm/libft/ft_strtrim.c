/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:18:39 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/02 21:51:31 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;

	if (!s || !(s1 = ft_strdup(s)))
		return (NULL);
	s = s1;
	while (*s1)
		s1++;
	while (ft_isspace(*s))
		s++;
	while (ft_isspace(*s1) || *s1 == '\0')
		s1--;
	*++s1 = '\0';
	return (ft_strdup(s));
}
