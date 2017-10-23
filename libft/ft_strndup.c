/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:55:03 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 20:55:43 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t len)
{
	char	*src;

	if (!(src = ft_strnew(len)))
		return (NULL);
	if (!(src = ft_strncpy(src, str, len)))
		return (NULL);
	return (src);
}
