/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 10:43:22 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/03 18:30:01 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*cat;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2) + 1;
		cat = (char *)malloc(i * sizeof(char));
		if (cat)
		{
			ft_strcpy(cat, s1);
			ft_strcat(cat, s2);
			return (cat);
		}
	}
	return (0);
}
