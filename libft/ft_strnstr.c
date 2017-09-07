/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:54:20 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/27 17:54:21 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	char	*ptr;
	char	*ptr1;
	char	*ptr2;
	int		flag;
	int		i;

	i = -1;
	ptr = (char *)big;
	while (*ptr && (++i < ((int)len - (int)ft_strlen(lit) + 1)))
	{
		flag = 1;
		ptr1 = ptr;
		ptr2 = (char *)lit;
		while (*ptr2)
		{
			if (*ptr2 != *ptr1)
				flag = 0;
			ptr1++;
			ptr2++;
		}
		if (flag == 1)
			return (ptr);
		ptr++;
	}
	return (0);
}
