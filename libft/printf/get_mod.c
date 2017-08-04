/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:36:22 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/13 16:36:25 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	get_mod(char fr, char fl)
{
	if (fl == 'j')
		return (fl);
	else if (fr == 'h' && fl == 'h')
		fl = 'f';
	else if (fr == 'h' && fl == 'f')
		fl = 'h';
	else if (fr == 'l' && fl == 'l')
		fl = 'm';
	else if (fr == 'l' && fl == 'm')
		fl = 'l';
	else if (fr > fl || fr == 'j')
		fl = fr;
	return (fl);
}
