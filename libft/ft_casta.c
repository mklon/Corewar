/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:54:45 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 23:15:03 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_dable_a(long double nb, int len, t_srt *lst)
{
	int		i;
	int		a;
	char	*s;
	char	*src;

	i = 0;
	len += 4;
	s = ft_strs(ft_strnew(len), &i, 1);
	nb -= 1.0;
	nb != 0 ? s[i++] = '.' : 0;
	while (i < len && nb != 0)
	{
		nb *= 16;
		a = (int)nb;
		nb = nb - (double)a;
		s[i] = ft_char(a);
		i++;
	}
	s[i] = '\0';
	if ((int)ft_strlen(s) < lst->accur)
	{
		src = ft_strnew((size_t)lst->accur + 4);
		s = ft_strcpychar(src, s, lst->accur + 4, '0');
	}
	return (nb == 0 && len > i ? s : ft_okrug_a(s));
}

char	*ft_str_zero(long double nb, t_srt *lst, char *s)
{
	char	*str;
	char	*src;
	int		i;

	i = 0;
	nb = ft_r_nbr(nb);
	str = ft_strnew(4);
	str = ft_strs(str, &i, (int)nb);
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

void	ft_ppp(char *c, char *b)
{
	if ((*c) >= '0' && (*c) < '9')
		(*c) += 1;
	else if ((*c) == '9')
		(*c) = 'a';
	else if ((*c) >= 97 && (*c) < 102)
		(*c) += 1;
	else if ((*c) == 102)
	{
		if ((*b) >= '0' && (*b) <= '9')
			(*b) += 1;
		else if ((*b) >= 97 && (*b) < 102)
			(*b) += 1;
		(*c) = '0';
	}
}

char	*ft_okrug_a(char *str)
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
		ft_ppp(&c, &b);
	str[i] = c;
	str[++i] = '\0';
	return (str);
}

char	*ft_zero(int len)
{
	char	*str;

	str = ft_strnew((size_t)len);
	while (len >= 0)
	{
		str[len] = '0';
		len--;
	}
	return (str);
}
