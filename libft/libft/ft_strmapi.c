/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:21:45 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/10 17:58:55 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*n;
	size_t			l;
	size_t			i;

	i = 0;
	if (s == '\0' || !f)
		return (NULL);
	l = ft_strlen(s) + 1;
	n = (char *)malloc(l * sizeof(char));
	if (n)
	{
		while (s[i])
		{
			n[i] = f(i, s[i]);
			i++;
		}
		n[i] = '\0';
	}
	return (n);
}
