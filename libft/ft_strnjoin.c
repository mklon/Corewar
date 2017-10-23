/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:53:57 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 20:54:30 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*s;

	if (!s1 || !s2 || !(s = ft_strnew(ft_strlen(s1) + len)))
		return (NULL);
	s = ft_strcpy(s, s1);
	s = ft_strncat(s, s2, len);
	return (s);
}
