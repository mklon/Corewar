/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:17:56 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/20 18:27:26 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		*ft_int_strnew(size_t len, int j)
{
	size_t	i;
	int		*arr;

	i = 0;
	if (!(arr = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	while (i < len)
	{
		arr[i++] = j;
	}
	return (arr);
}
