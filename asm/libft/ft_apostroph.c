/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apostroph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:52:16 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:56:44 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lendigit(int i)
{
	int	len;

	len = 0;
	while (i >= 0)
	{
		if (i % 3 == 0)
			len++;
		i--;
	}
	return (len);
}

char	*ft_strcpy_re(char *str)
{
	char	*src;
	int		i;
	int		j;

	i = 0;
	j = (int)ft_strlen(str);
	src = ft_strnew((size_t)j);
	j--;
	if (str[j] == ',')
		j--;
	while (j >= 0)
	{
		src[i] = str[j];
		i++;
		j--;
	}
	src[i] = '\0';
	ft_strdel(&str);
	return (src);
}

char	*ft_apostroph(char *str, t_srt *lst)
{
	int		i;
	int		j;
	char	*src;
	int		len;

	i = 1;
	len = -1;
	if (lst->ap == 1)
	{
		j = (int)ft_strlen(str);
		src = ft_strnew((size_t)(j + ft_lendigit(j)));
		j--;
		while (j >= 0)
		{
			src[++len] = (i % 4 == 0) ? ',' : str[j];
			j--;
			i++;
		}
		src[++len] = '\0';
		ft_strdel(&str);
		src = ft_strcpy_re(src);
		return (src);
	}
	return (str);
}
