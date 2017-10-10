/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:51:58 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/12 11:09:25 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *s;

	if (!s1 || !s2)
		return (NULL);
	if (!(s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	s = ft_strcpy(s, s1);
	s = ft_strcat(s, s2);
	return (s);
}
