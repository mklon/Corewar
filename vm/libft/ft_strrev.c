/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:22:37 by oposhiva          #+#    #+#             */
/*   Updated: 2016/12/06 17:22:38 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		end;
	int		temp;
	char	p;

	i = 0;
	temp = ft_strlen(str);
	end = temp / 2;
	while (i < end)
	{
		p = str[i];
		str[i] = str[temp - 1];
		str[temp - 1] = p;
		i++;
		temp--;
	}
	return (str);
}
