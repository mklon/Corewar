/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:34:39 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/30 14:34:39 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*temp;

	temp = malloc(sizeof(char) * size);
	if (temp == NULL)
		return (NULL);
	ft_bzero(temp, size);
	return (temp);
}
