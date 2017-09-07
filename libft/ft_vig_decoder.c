/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vig_decoder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:38:56 by oposhiva          #+#    #+#             */
/*   Updated: 2016/12/06 16:38:57 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_vig_decoder(char *text, char *pass)
{
	char *p;
	char *t;

	p = pass;
	t = text;
	while (*text)
	{
		*text -= *pass;
		if ((char)*text < 32)
			*text += 95;
		if ((char)*text < 32)
			*text += 95;
		text++;
		pass++;
		if (!(*pass))
			pass = p;
	}
	return (t);
}
