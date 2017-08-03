/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:51:35 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/09 22:26:41 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*n;
	size_t	l;
	size_t	i;

	i = 0;
	if (s && f)
	{
		l = ft_strlen(s) + 1;
		n = (char *)malloc(l * sizeof(char));
		if (n)
		{
			while (s[i])
			{
				n[i] = f(s[i]);
				i++;
			}
			n[i] = '\0';
		}
		return (n);
	}
	return (0);
}
