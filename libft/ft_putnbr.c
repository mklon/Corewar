/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:58:20 by oposhiva          #+#    #+#             */
/*   Updated: 2016/12/03 18:58:22 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		ft_putnbr(int n)
{
	int			len;
	long int	i;
	long int	j;
	long int	nn;

	nn = n;
	len = ft_n_dec(nn);
	if (nn < 0)
	{
		ft_putchar('-');
		nn *= -1;
		len--;
	}
	i = nn;
	j = 1;
	while (--len > 0)
		j *= 10;
	len = ft_n_dec(nn) + 1;
	while (--len > 0)
	{
		i = nn / j;
		nn = nn - i * j;
		j /= 10;
		ft_putchar((char)(i + '0'));
	}
}
