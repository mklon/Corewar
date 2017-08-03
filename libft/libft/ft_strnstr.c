/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:27:09 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/19 21:11:41 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l;

	if (!(*little))
		return ((char *)big);
	l = ft_strlen(little);
	while (*big && len-- >= l)
	{
		if (*(unsigned char *)big == *(unsigned char *)little)
		{
			if (!ft_memcmp(big, little, l))
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
