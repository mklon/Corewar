/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:02:52 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/25 13:02:54 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *append)
{
	char	*d;

	d = (char*)destination;
	while (*d)
		d++;
	while (*append)
		*d++ = *(char*)append++;
	*d = '\0';
	return (destination);
}
