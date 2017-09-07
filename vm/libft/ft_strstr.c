/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:55:55 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/26 15:55:56 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str_b, const char *str_a)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	if (!str_a[0])
		return ((char*)str_b);
	while (str_b[i])
	{
		j = i;
		l = 0;
		while (str_b[j] == str_a[l])
		{
			j++;
			l++;
			if (str_a[l] == '\0')
				return ((char*)&str_b[i]);
		}
		i++;
	}
	return (NULL);
}
