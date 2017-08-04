/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:56:11 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/12 14:25:30 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	l;
	size_t	b;

	if (!(*little))
		return ((char *)big);
	l = ft_strlen(little);
	b = ft_strlen(big);
	while (b-- >= l && *big)
	{
		if (*(unsigned char *)big == *(unsigned char *)little)
		{
			if (!ft_memcmp(big, little, l))
				return ((char *)big);
		}
		big++;
	}
	return (0);
}
