/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coding_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:22:36 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 17:22:44 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	serch_code_arg(int nb)
{
	if (nb == T_DIR)
		return (DIR_CODE);
	else if (nb == T_REG)
		return (REG_CODE);
	else
		return (IND_CODE);
}

int			ft_coding_byt(t_prog *prog)
{
	int		coding_byt;
	int		i;
	int		offset_bit;

	i = -1;
	offset_bit = 6;
	coding_byt = 0;
	while (++i < g_tab[prog->i].count_arg)
	{
		coding_byt += serch_code_arg(prog->arg[i]) << offset_bit;
		offset_bit -= 2;
	}
	return (coding_byt);
}
