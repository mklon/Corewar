/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caststr_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:26:56 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:51:37 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		rang2(long double nb, int *i)
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

char			ft_char2(int a)
{
	char	c;

	c = '0';
	if (a >= 0 && a <= 9)
		c = a + 48;
	else if (a == 10)
		c = 'A';
	else if (a == 11)
		c = 'B';
	else if (a == 12)
		c = 'C';
	else if (a == 13)
		c = 'D';
	else if (a == 14)
		c = 'E';
	else if (a == 15)
		c = 'F';
	return (c);
}

char			*ft_strs2(char *s, int *i, int nb)
{
	char	*s1;

	s1 = ft_itoa(nb);
	s[(*i)++] = '0';
	s[(*i)++] = 'X';
	s[(*i)++] = s1[0];
	s[(*i)] = '\0';
	ft_strdel(&s1);
	return (s);
}

char			*ft_pow_a2(int pow)
{
	char	*s1;
	char	*s2;

	s1 = ft_strnew(2);
	s1[0] = 'P';
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

char			*ft_getstr_a2(long double nb, t_srt *lst)
{
	int		i;
	char	*s;
	char	*s1;

	if (nb == 0.0)
		return (ft_strdup("0X0P+0"));
	i = 0;
	nb = rang(nb, &i);
	s1 = ft_pow_a2(i);
	if (lst->accur == 0)
		return (ft_str_zero2(nb, lst, s1));
	if (lst->accur > 0)
	{
		s = ft_str_dable_a2(nb, lst->accur + 1, lst, 0);
		s = ft_strjoin(s, s1);
	}
	else
	{
		s = ft_str_dable_a2(nb, 14, lst, 0);
		s = ft_strjoin(s, s1);
	}
	return (s);
}
