/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caststra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:37:09 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:50:59 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_dable_a2(long double nb, int len, t_srt *lst, int i)
{
	int		a;
	char	*s;
	char	*src;

	len += 4;
	s = ft_strnew(len);
	s = ft_strs2(s, &i, 1);
	nb -= 1.0;
	if (nb != 0)
		s[i++] = '.';
	while (i < len && nb != 0)
	{
		nb *= 16;
		a = (int)nb;
		nb = nb - (double)a;
		s[i] = ft_char2(a);
		i++;
	}
	s[i] = '\0';
	if ((int)ft_strlen(s) < lst->accur)
	{
		src = ft_strnew((size_t)lst->accur + 4);
		s = ft_strcpychar(src, s, lst->accur + 4, '0');
	}
	return ((nb == 0 && len > i) ? s : ft_okrug_a2(s));
}

char	*ft_str_zero2(long double nb, t_srt *lst, char *s)
{
	char	*str;
	char	*src;
	int		i;

	i = 0;
	nb = ft_r_nbr(nb);
	str = ft_strnew(4);
	str = ft_strs2(str, &i, (int)nb);
	if (lst->hesh == 1)
	{
		src = ft_strnew((ft_strlen(str) + 1));
		i = 0;
		while (str[i])
		{
			src[i] = str[i];
			i++;
		}
		src[i] = '.';
		src[++i] = '\0';
		src = ft_strjoin(src, s);
		ft_strdel(&str);
		return (src);
	}
	str = ft_strjoin(str, s);
	return (str);
}

void	ft_ppp2(char *c, char *b)
{
	if ((*c) >= '0' && (*c) < '9')
		(*c) += 1;
	else if ((*c) == '9')
		(*c) = 'A';
	else if ((*c) >= 65 && (*c) < 69)
		(*c) += 1;
	else if ((*c) == 70)
	{
		if ((*b) >= '0' && (*b) <= '9')
			(*b) += 1;
		else if ((*b) >= 55 && (*b) < 69)
			(*b) += 1;
		(*c) = '0';
	}
}

char	*ft_okrug_a2(char *str)
{
	int		i;
	char	c;
	char	a;
	char	b;

	i = ft_strlen(str);
	a = str[--i];
	c = str[--i];
	b = str[i];
	if (a >= '8')
		ft_ppp2(&c, &b);
	str[i] = c;
	str[++i] = '\0';
	return (str);
}
