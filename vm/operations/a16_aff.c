/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a16_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:48:37 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/10/11 21:48:38 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	aff_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	if (gen->aff)
	{
		uncode_args(gen->field, process, op_num, args);
		if (!gen->visual)
			ft_printf("Aff: %c\n", (char)process->reg[args[0]]);
		else
		{
			wmove(gen->board, 63, 0);
			wprintw(gen->board, "Aff: %c\n", (char)process->reg[args[0]]);
		}
	}
}
