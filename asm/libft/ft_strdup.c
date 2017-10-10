/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:34:00 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/02 15:20:05 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = ft_memalloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	else
	{
		s2 = ft_strcpy(s2, s1);
		return (s2);
	}
}
