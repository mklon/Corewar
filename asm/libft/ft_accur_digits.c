/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accur_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:17:30 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 22:23:42 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_accur_digits(char *str, t_srt *lst)
{
	char	*src;

	if (lst->accur != -1)
	{
		if ((lst->letar == 'O' || lst->letar == 'o') && lst->hesh != 0)
			lst->accur -= 1;
		if (lst->accur == 0 && str[0] == '0')
			return (ft_strdup("\0"));
		if ((int)ft_strlen(str) <= lst->accur)
		{
			if ((src = ft_strnew((size_t)lst->accur)) == NULL)
				return (NULL);
			if (lst->zero_or_minus == '1' && lst->accur < lst->width)
			{
				lst->zero_or_minus = '0';
				lst->space = ' ';
			}
			return (ft_strcpy_rev(src, str, '0', lst->accur));
		}
	}
	return (str);
}

char	*ft_hesh(t_srt *lst, char *str)
{
	str = ft_width(str, lst);
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

char	*ft_strhesh(char *str, t_srt *lst)
{
	char	*src;
	int		i;
	int		j;

	j = -1;
	i = 0;
	if ((lst->hesh == 1) && (lst->letar == 'x' || lst->letar == 'X'))
	{
		if (lst->width != -1 && lst->zero_or_minus == '1')
			return (ft_hesh(lst, str));
		src = ft_strnew(ft_strlen(str) + 2);
		src[i++] = '0';
		src[i++] = 'x';
		while (str[++j])
			src[i++] = str[j];
		src[i] = '\0';
		ft_strdel(&str);
		return (ft_width(src, lst));
	}
	else if (lst->hesh == 1 && (lst->letar == 'o' || lst->letar == 'O'))
		return (ft_space(str, '0', ((int)ft_strlen(str) + 1), lst));
	str = ft_width(str, lst);
	return (str);
}

char	*ft_space(char *str, char c, int len, t_srt *lst)
{
	char	*src;

	src = ft_strnew((size_t)len);
	src = ft_strcpy_rev(src, str, c, len);
	if (lst->hesh == 1 && (lst->letar == 'o' || lst->letar == 'O'))
		return (ft_width(src, lst));
	return (src);
}
