/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:20:02 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:36:51 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	signed_size(va_list ap, t_srt *lst)
{
	intmax_t	nbr;

	nbr = va_arg(ap, intmax_t);
	if (lst->size == 1)
		nbr = (signed char)nbr;
	else if (lst->size == 2)
		nbr = (signed short int)nbr;
	else if (lst->size == 3)
		nbr = (long int)nbr;
	else if (lst->size == 4)
		nbr = (long long int)nbr;
	else if (lst->size == 5)
		nbr = (intmax_t)nbr;
	else if (lst->size == 6)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t	unsigned_size(va_list ap, t_srt *lst)
{
	uintmax_t	nbr;

	nbr = va_arg(ap, uintmax_t);
	if (lst->size == 1)
		nbr = (unsigned char)nbr;
	else if (lst->size == 2)
		nbr = (unsigned short int)nbr;
	else if (lst->size == 3)
		nbr = (unsigned long int)nbr;
	else if (lst->size == 4)
		nbr = (unsigned long long int)nbr;
	else if (lst->size == 5)
		nbr = (uintmax_t)nbr;
	else if (lst->size == 6)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
