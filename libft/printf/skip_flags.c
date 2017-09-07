/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:35:57 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/13 16:36:02 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

const char		*skip_flags(const char *fr, char *fl)
{
	while ((FLAG_SIG(*fr) || FLAG_NUM(*fr) || FLAG_MOD(*fr) || FLAG_SKIP(*fr)
			|| FLAG_SIG2(*fr)) && *fr)
	{
		if (FLAG_MOD(*fr))
			*fl = get_mod(*fr, *fl);
		fr++;
	}
	return (fr);
}
