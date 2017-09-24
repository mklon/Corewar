/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_digits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:33:11 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/06 13:33:26 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_extract_digits(int *res, char *str, size_t i)
{
	long int	n;

	n = 0;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i] - '0');
		if (!(ft_isint(n)))
			return (0);
		i++;
	}
	*res = (int)n;
	return (i);
}
