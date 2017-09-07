/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:44:06 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/09 22:37:17 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_trim(char const *s, int begin, int end)
{
	char		*n;
	size_t		i;

	i = 0;
	if (end < begin)
		return (0);
	n = (char *)malloc((end - begin + 2) * sizeof(char));
	if (n)
	{
		while (begin <= end && s[begin])
		{
			n[i] = s[begin];
			i++;
			begin++;
		}
		n[i] = '\0';
		return (n);
	}
	return (0);
}
