/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:17:58 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 22:16:49 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_print_wchar_str(va_list ap, t_srt *lst)
{
	int		i;
	wchar_t	*str;
	char	*src;
	int		j;
	int		len;

	j = -1;
	str = va_arg(ap, wchar_t *);
	if (str == NULL)
	{
		src = ft_strdup("(null)");
		src = ft_accur(src, lst);
		src = ft_width(src, lst);
		return (src);
	}
	len = ft_len_wchar(str);
	if (lst->accur != -1 && lst->accur < len)
		len = lst->accur;
	src = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	while (str[++i] && len != 0)
		ft_print_wchar(str[i], src, &j, &len);
	src[++j] = '\0';
	return (ft_width(ft_accur(src, lst), lst));
}

void	ft_print_wchar(wchar_t c, char *str, int *i, int *len)
{
	if (c <= 0x7F && 1 <= (*len)--)
		str[++(*i)] = (char)c;
	else if (c <= 0x7FF && (*len) >= 2)
	{
		str[++(*i)] = (char)((c >> 6) + 0xC0);
		str[++(*i)] = (char)((c & 0x3F) + 0x80);
		(*len) -= 2;
	}
	else if (c <= 0xFFFF && (*len) >= 3)
	{
		str[++(*i)] = (char)((c >> 12) + 0xE0);
		str[++(*i)] = (char)(((c >> 6) & 0x3F) + 0x80);
		str[++(*i)] = (char)((c & 0x3F) + 0x80);
		(*len) -= 3;
	}
	else if (c <= 0x10FFFF && (*len) >= 4)
	{
		str[++(*i)] = (char)((c >> 18) + 0xF0);
		str[++(*i)] = (char)(((c >> 12) & 0x3F) + 0x80);
		str[++(*i)] = (char)(((c >> 6) & 0x3F) + 0x80);
		str[++(*i)] = (char)((c & 0x3F) + 0x80);
		(*len) -= 4;
	}
}

int		ft_len_wchar(wchar_t *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] <= 0x7F)
			len += 1;
		else if (str[i] <= 0x7FF)
			len += 2;
		else if (str[i] <= 0xFFFF)
			len += 3;
		else if (str[i] <= 0x10FFFF)
			len += 4;
		i++;
	}
	return (len);
}
