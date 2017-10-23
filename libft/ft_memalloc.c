/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:41:08 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/16 18:59:35 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*res;

	res = (void *)malloc(sizeof(void *) * size);
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, size);
	return (res);
}
