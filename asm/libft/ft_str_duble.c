/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_duble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:22:48 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:35:47 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pow(long double nb, int len)
{
	int		i;
	char	*str;
	char	*src;

	i = -1;
	str = ft_strnew((size_t)len);
	while (len > 0)
	{
		if (nb < 1)
			str[++i] = '0';
		nb *= 10;
		len--;
	}
	str[i] = '\0';
	nb = ft_r_nbr(nb);
	src = ft_itoa((int)nb);
	if (i > -1)
		src = ft_strjoin(str, src);
	return (src);
}

char	*ft_cast(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = (int)ft_strlen(s1) + (int)ft_strlen(s2) + 1;
	s = (char *)malloc(sizeof(char) * len);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i++] = '.';
	while (i < len)
	{
		s[i] = s2[j];
		j++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_okrug(long double nb, t_srt *lst)
{
	char	*str;
	char	*src;
	int		i;

	i = 0;
	nb = ft_r_nbr(nb);
	str = ft_itoa((int)nb);
	str = ft_apostroph(str, lst);
	if (lst->hesh == 1)
	{
		src = ft_strnew((ft_strlen(str) + 1));
		while (str[i])
		{
			src[i] = str[i];
			i++;
		}
		src[i] = '.';
		src[++i] = '\0';
		ft_strdel(&str);
		return (src);
	}
	return (str);
}

char	*ft_str_double(long double nb, t_srt *lst)
{
	char		*s1;
	char		*s2;
	long double	a;
	int			len;

	if (lst->accur == 0)
		return (ft_okrug(nb, lst));
	a = (long long int)nb;
	nb -= a;
	len = 6;
	if (lst->accur > 0)
		len = lst->accur;
	if (nb == 0.0)
		s2 = ft_zero(len);
	if (nb < 0)
		s2 = ft_pow(-nb, len);
	else
		s2 = ft_pow(nb, len);
	s1 = itoa((long long int)a);
	s1 = ft_apostroph(s1, lst);
	s1 = ft_cast(s1, s2);
	ft_strdel(&s2);
	return (s1);
}
