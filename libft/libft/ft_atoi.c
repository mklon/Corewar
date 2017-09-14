/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:12:58 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/19 16:46:57 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int					s;
	unsigned long int	r;

	r = 0;
	s = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		r = r * 10 + (*str - '0');
		if (r >= 9223372036854775807 && s == 1)
			return (-1);
		if (r > 9223372036854775807 && s == -1)
			return (0);
		str++;
	}
	return ((int)(r * s));
}
