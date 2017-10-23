/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:10:06 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:17:03 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;

	res = 0;
	va_start(ap, format);
	res = ft_format(format, ap);
	va_end(ap);
	return (res);
}
