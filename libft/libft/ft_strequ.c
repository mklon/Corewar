/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:37:19 by msymkany          #+#    #+#             */
/*   Updated: 2016/11/30 19:48:57 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 == '\0' && s2 == '\0')
		return (0);
	if (s1 && s2 && (ft_strcmp(s1, s2) == 0))
		return (1);
	return (0);
}
