/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caststr_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:10:37 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:29:28 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	rang(long double nb, int *i)
{
	if (nb < 1)
	{
		while ((int)nb != 1)
		{
			nb *= 2;
			(*i)--;
		}
	}
	else if (nb > 1)
	{
		while ((int)nb != 1)
		{
			nb /= 2;
			(*i)++;
		}
	}
	return (nb);
}

char		ft_char(int a)
{
	char	c;

	c = '0';
	if (a >= 0 && a <= 9)
		c = a + 48;
	else if (a == 10)
		c = 'a';
	else if (a == 11)
		c = 'b';
	else if (a == 12)
		c = 'c';
	else if (a == 13)
		c = 'd';
	else if (a == 14)
		c = 'e';
	else if (a == 15)
		c = 'f';
	return (c);
}

char		*ft_strs(char *s, int *i, int nb)
{
	char	*s1;

	s1 = ft_itoa(nb);
	s[(*i)++] = '0';
	s[(*i)++] = 'x';
	s[(*i)++] = s1[0];
	s[(*i)] = '\0';
	ft_strdel(&s1);
	return (s);
}

char		*ft_pow_a(int pow)
{
	char	*s1;
	char	*s2;

	s1 = ft_strnew(1);
	s1[0] = 'p';
	if (pow < 0)
	{
		s1[1] = '-';
		s1[2] = '\0';
		s2 = ft_itoa(-pow);
	}
	else
	{
		s1[1] = '+';
		s1[2] = '\0';
		s2 = ft_itoa(pow);
	}
	s1 = ft_strjoin(s1, s2);
	return (s1);
}

char		*ft_getstr_a(long double nb, t_srt *lst)
{
	int		i;
	char	*s;
	char	*s1;

	if (nb == 0.0)
		return (ft_strdup("0x0p+0"));
	i = 0;
	nb = rang(nb, &i);
	s1 = ft_pow_a(i);
	if (lst->accur == 0)
		return (ft_str_zero(nb, lst, s1));
	if (lst->accur > 0)
	{
		s = ft_str_dable_a(nb, lst->accur + 1, lst);
		s = ft_strjoin(s, s1);
	}
	else
	{
		s = ft_str_dable_a(nb, 14, lst);
		s = ft_strjoin(s, s1);
	}
	return (s);
}
