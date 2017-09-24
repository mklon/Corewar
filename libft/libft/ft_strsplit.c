/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:07:58 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/10 14:03:20 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char		**spl;
	size_t		i;
	size_t		j;
	size_t		w;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if ((spl = (char **)malloc((ft_w_c(s, c) + 1) * sizeof(char *))) == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			w = i;
			while (s[i] && s[i] != c)
				i++;
			spl[j++] = ft_strsub(s, w, i - w);
		}
	}
	spl[ft_w_c(s, c)] = NULL;
	return (spl);
}
