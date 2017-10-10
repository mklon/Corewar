/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:31:12 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/23 13:41:30 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		tayp(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd')
		return (1);
	if (c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u')
		return (1);
	if (c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (1);
	if (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'b')
		return (1);
	if (c == 'a' || c == 'A' || c == 'g' || c == 'G' || c == 'n')
		return (1);
	return (0);
}

int		flag_format(char c, t_srt *lst)
{
	if (c == '-')
	{
		lst->zero_or_minus = '-';
		return (1);
	}
	else if (c == '0' && lst->zero_or_minus != '-')
	{
		lst->zero_or_minus = '1';
		return (1);
	}
	else if (c == '+')
	{
		lst->plus = '+';
		lst->space = '0';
		return (1);
	}
	else if (c == ' ' && lst->plus != '+')
	{
		lst->space = ' ';
		return (1);
	}
	else
		return (0);
}

int		add_dot(const char *str, int *i, t_srt *lst, va_list ap)
{
	int	len;

	if (str[(*i)] == '.')
	{
		if (str[(*i) + 1] == '*')
		{
			len = va_arg(ap, int);
			if (len >= 0 && lst->accur == -1)
				lst->accur = len;
			(*i)++;
			return (1);
		}
		else
		{
			(*i)++;
			len = atoidig(str, i);
			if (lst->accur == -1)
				lst->accur = len;
			return (1);
		}
	}
	return (0);
}
