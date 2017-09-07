/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:08:37 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/30 17:08:37 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	int		i;

	i = -1;
	if (s != NULL && *f != NULL)
	{
		if ((temp = malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
			return (NULL);
		while (s[++i])
			temp[i] = f(i, s[i]);
		temp[i] = '\0';
		return (temp);
	}
	return (NULL);
}
