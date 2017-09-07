/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:18:55 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/30 17:18:55 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*temp;
	size_t			index;

	index = -1;
	if (s != NULL)
	{
		if ((temp = malloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		while (++index < len)
			*temp++ = *(s++ + start);
		*temp = '\0';
		return (temp - len);
	}
	return (NULL);
}
