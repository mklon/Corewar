/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:54:06 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/17 19:16:54 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_strndup(char *str, int len)
{
	char	*src;

	if (!(src = ft_strnew((size_t)len)))
		return (NULL);
	src = ft_strncpy(src, str, len);
	src[len] = '\0';
	if (ft_strcmp(str, "(null)") != 0)
		free(str);
	return (src);
}

char	*ft_accur(char *str, t_srt *lst)
{
	if (lst->accur != -1)
		return (my_strndup(str, lst->accur));
	else
		return (str);
}
