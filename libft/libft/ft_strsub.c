/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:13:57 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/09 22:33:29 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*n;
	size_t			i;

	i = 0;
	n = (char *)malloc((len + 1) * sizeof(char));
	if (n == NULL || s == NULL || start > (unsigned int)ft_strlen(s))
		return (NULL);
	while (len-- && s[start])
	{
		n[i] = s[start];
		start++;
		i++;
	}
	n[i] = '\0';
	return (n);
}
