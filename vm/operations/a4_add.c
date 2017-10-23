/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a4_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:46:31 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/10/11 21:46:31 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	add_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uncode_args(gen->field, process, op_num, args);
	if (args[0] >= 1 && args[0] <= REG_NUMBER &&
		args[1] >= 1 && args[1] <= REG_NUMBER &&
		args[2] >= 1 && args[2] <= REG_NUMBER)
	{
		process->reg[args[2]] = process->reg[args[0]] + process->reg[args[1]];
		process->carry = (char)((process->reg[args[2]] == 0) ? 1 : 0);
		if (gen->debug)
		{
			ft_printf("P%7u | add r%u r%u r%u -> %d + %d = %d\n", process->num,
					args[0], args[1], args[2], process->reg[args[0]],
					process->reg[args[1]], process->reg[args[2]]);
		}
	}
}
