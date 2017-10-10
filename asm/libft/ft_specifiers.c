/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:47:06 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:19:53 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_specifiers(const char *str, int *i, t_srt *list)
{
	if (str[(*i)] == 'z' && list->size < 6)
		list->size = 6;
	else if (str[(*i)] == 'L' && list->size < 7)
		list->size = 7;
	else if (str[(*i)] == 'j' && list->size < 5)
		list->size = 5;
	else if ((str[(*i)] == 'l' && str[(*i) + 1] == 'l') && list->size < 4)
	{
		list->size = 4;
		(*i)++;
	}
	else if (str[(*i)] == 'l' && list->size < 3)
		list->size = 3;
	else if ((str[(*i)] == 'h' && str[(*i) + 1] == 'h') && list->size < 1)
	{
		list->size = 1;
		(*i)++;
	}
	else if (str[(*i)] == 'h' && list->size < 2)
		list->size = 2;
}
