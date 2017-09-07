/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vig_coder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:44:44 by oposhiva          #+#    #+#             */
/*   Updated: 2016/12/06 16:44:45 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_vig_coder(char *text, char *pass)
{
	char *p;
	char *t;

	p = pass;
	t = text;
	while (*text)
	{
		*text += *pass;
		if ((unsigned char)*text > 126)
			*text -= 95;
		if ((unsigned char)*text > 126)
			*text -= 95;
		text++;
		pass++;
		if (!(*pass))
			pass = p;
	}
	return (t);
}
