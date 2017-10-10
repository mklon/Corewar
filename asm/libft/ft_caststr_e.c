/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caststr_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:40:33 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:21:40 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	rang_e(long double nb, int *i)
{
	if (nb == 0.0)
		return (nb);
	if (nb > 1)
	{
		while (nb > 10)
		{
			nb /= 10;
			(*i)++;
		}
	}
	else if (nb < 1)
	{
		while (nb < 1)
		{
			nb *= 10;
			(*i)--;
		}
	}
	return (nb);
}

char		*ft_str_ost(char *s, int i)
{
	if (i < 0)
	{
		s[1] = '-';
		return (ft_itoa(-i));
	}
	else
	{
		s[1] = '+';
		return (ft_itoa(i));
	}
}

char		*ft_getpow(int i)
{
	char	*s1;
	char	*s2;

	s1 = ft_strnew(4);
	s1[0] = 'e';
	s2 = ft_str_ost(s1, i);
	if (i >= -9 && i <= 9)
	{
		s1[2] = '0';
		s1[3] = s2[0];
	}
	else
	{
		s1[2] = s2[0];
		s1[3] = s2[1];
	}
	s1[4] = '\0';
	ft_strdel(&s2);
	return (s1);
}

char		*ft_get_str_e(long double nb, t_srt *lst)
{
	char	*s;
	char	*s1;
	int		i;

	i = 0;
	nb = rang_e(nb, &i);
	s = ft_str_double(nb, lst);
	s1 = ft_getpow(i);
	s = ft_strjoin(s, s1);
	return (s);
}
