/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:20:19 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/30 15:20:19 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*temp;

	temp = malloc(sizeof(char) * size + 1);
	if (temp == NULL)
		return (NULL);
	ft_bzero(temp, size + 1);
	return (temp);
}
