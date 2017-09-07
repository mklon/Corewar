/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:15:41 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/25 12:15:42 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destination, const char *source)
{
	char	*d;

	d = (char*)destination;
	while (*source != '\0')
	{
		*d = *source;
		d++;
		source++;
	}
	*d = '\0';
	return (destination);
}
