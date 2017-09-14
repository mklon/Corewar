/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_w_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:19:56 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/10 14:02:19 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_w_c(char const *s, char c)
{
	size_t		w;
	char		*pt;

	if (s == '\0')
		return (0);
	pt = (char *)s;
	w = 0;
	while (*pt)
	{
		while (*pt && *pt == c)
			pt++;
		if (*pt)
		{
			while (*pt && *pt != c)
				pt++;
			w++;
		}
	}
	return (w);
}
