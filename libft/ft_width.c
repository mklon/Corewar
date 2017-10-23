/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 20:54:56 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 23:25:00 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_rev(char *s1, char *s2, char c, int j)
{
	int	i;

	i = (int)ft_strlen(s2);
	while (i >= 0)
	{
		s1[j] = s2[i];
		i--;
		j--;
	}
	while (j >= 0)
	{
		s1[j] = c;
		j--;
	}
	if (s2[0] == '\0')
		return (s1);
	ft_strdel(&s2);
	return (s1);
}

char	*ft_strcpychar(char *s1, char *s2, int j, char c)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < j)
	{
		s1[i] = c;
		i++;
	}
	s1[i] = '\0';
	ft_strdel(&s2);
	return (s1);
}

char	*ft_width(char *str, t_srt *lst)
{
	char	*src;

	if (lst->width != -1)
	{
		if (lst->width < -1)
		{
			lst->width *= -1;
			lst->zero_or_minus = '-';
		}
		if ((int)ft_strlen(str) < lst->width)
		{
			src = ft_strnew((size_t)lst->width);
			if (lst->zero_or_minus == '1')
				return (ft_strcpy_rev(src, str, '0', lst->width));
			else if (lst->space == ' ')
				return (ft_strcpy_rev(src, str, ' ', lst->width));
			else if (lst->zero_or_minus == '-')
				return (ft_strcpychar(src, str, lst->width, ' '));
			return (ft_strcpy_rev(src, str, ' ', lst->width));
		}
		else
			return (str);
	}
	return (str);
}

char	*ft_plus2(char *str, t_srt *lst)
{
	int	i;

	i = 0;
	str = ft_width(str, lst);
	if (lst->plus != '0')
	{
		if ((lst->width == -1 && lst->zero_or_minus == '1')
		|| (int)ft_strlen(str) > lst->width)
			return (ft_plus(str, lst));
		while (ft_isdigit(str[i]) != 1)
			i++;
		str[i] = lst->plus;
	}
	return (str);
}

char	*ft_plus(char *str, t_srt *lst)
{
	char	*src;
	int		i;
	int		j;

	i = -1;
	if (lst->plus != '0')
	{
		src = ft_strnew(ft_strlen(str) + 1);
		j = -1;
		while (ft_isdigit(str[++i]) == 0)
			src[++j] = str[i];
		if (j >= 0)
			src[j] = lst->plus;
		else
			src[++j] = lst->plus;
		while (str[i])
			src[++j] = str[i++];
		src[++j] = '\0';
		src = ft_width(src, lst);
		ft_strdel(&str);
		return (src);
	}
	return (str);
}
