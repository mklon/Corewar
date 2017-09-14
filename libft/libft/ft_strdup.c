/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:44:22 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/09 21:29:53 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*new;

	i = ft_strlen(s);
	new = (char *)malloc(++i * sizeof(char));
	if (new == NULL)
		return (NULL);
	new = ft_strcpy(new, s);
	return (new);
}
