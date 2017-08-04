/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:54:29 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/08 18:02:25 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	if ((s = (char *)malloc(sizeof(char) * (size + 1))))
	{
		ft_bzero(s, size + 1);
		return (s);
	}
	return (NULL);
}
