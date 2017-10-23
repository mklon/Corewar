/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:23:22 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 18:23:32 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		size_argument(t_prog *prg)
{
	int			i;
	int			size;

	i = -1;
	size = 0;
	while (++i < g_tab[prg->i].count_arg)
	{
		if (prg->arg[i] == T_IND
			|| (prg->arg[i] == T_DIR && g_tab[prg->i].flag_direct_size == 1))
			size += IND_SIZE;
		else if (prg->arg[i] == T_DIR)
			size += DIR_SIZE;
		else if (prg->arg[i] == T_REG)
			size += T_REG;
	}
	return (size);
}

unsigned int	ft_size_program(t_prog *prog)
{
	unsigned int	size;

	size = 1 + (unsigned int)size_argument(prog);
	if (g_tab[prog->i].coding_byte == 1)
		size += 1;
	return (size);
}
