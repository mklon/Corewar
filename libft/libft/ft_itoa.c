/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:32:41 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/09 22:41:14 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	count(int n)
{
	size_t		i;

	i = 0;
	if (n == 0 || n < 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_nbtostr(char *num, long int nb, size_t i)
{
	if (nb < 0)
	{
		*num = '-';
		nb = -nb;
	}
	num[i--] = '\0';
	if (nb == 0)
		num[i] = '0';
	while (nb > 0)
	{
		num[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (num);
}

char			*ft_itoa(int n)
{
	char		*num;
	long int	nb;
	size_t		j;

	nb = n;
	j = count(n);
	num = (char *)malloc((j + 1) * sizeof(char));
	if (num)
		return (ft_nbtostr(num, nb, j));
	return (NULL);
}
