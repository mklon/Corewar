/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:22:48 by oposhiva          #+#    #+#             */
/*   Updated: 2016/12/01 15:22:49 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		index;
	int		str1_len;
	int		str2_len;

	if (s1 != NULL && s2 != NULL)
	{
		index = -1;
		str1_len = ft_strlen(s1);
		str2_len = ft_strlen(s2);
		if ((temp = malloc(str1_len + str2_len + 1)) == NULL)
			return (NULL);
		while (++index < str1_len)
			*temp++ = *s1++;
		index = -1;
		while (++index < str2_len)
			*temp++ = *s2++;
		*temp = '\0';
		return (temp - (str1_len + str2_len));
	}
	return (NULL);
}
