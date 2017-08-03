/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:01:41 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/10 16:40:55 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*n;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
		return (ft_strnew(0));
	if (s)
	{
		i = ft_strlen(s) - 1;
		j = 0;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			if (i == 0)
				return (ft_strnew(0));
			i--;
		}
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j++;
		n = ft_trim(s, j, i);
		return (n);
	}
	return (NULL);
}
