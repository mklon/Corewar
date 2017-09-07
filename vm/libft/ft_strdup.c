/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:27:32 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/25 11:27:34 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		i;
	char	*temp;

	i = ft_strlen(str);
	temp = malloc(sizeof(char) * i + 1);
	if (temp == NULL)
		return (NULL);
	temp = ft_strcpy(temp, str);
	return (temp);
}
