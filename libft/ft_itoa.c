/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:36:04 by oposhiva          #+#    #+#             */
/*   Updated: 2016/12/03 14:36:04 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_n_dec(long int n)
{
	int			num;

	num = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
		num = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		num++;
	}
	return (num);
}

char		*ft_itoa(int n)
{
	int			i;
	long int	l;
	int			coef;
	int			size;
	char		*temp;

	i = 0;
	l = n;
	size = ft_n_dec(l);
	if ((temp = malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	if (l < 0)
	{
		l *= -1;
		i++;
		*temp = '-';
	}
	*(temp + (size--)) = '\0';
	while (i <= size)
	{
		coef = l % 10;
		l /= 10;
		*(temp + (size--)) = coef + '0';
	}
	return (temp);
}
