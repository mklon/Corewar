/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a9_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:47:44 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/10/11 21:47:45 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	zjmp_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uncode_args(gen->field, process, op_num, args);
	if (gen->debug)
	{
		ft_printf("P%7u | zjmp %hd -> %hd ", process->num, (short)args[0],
				((short)args[0] % IDX_MOD));
		(process->carry) ? ft_printf("OK\n") : ft_printf("FAIL\n");
	}
	if (process->carry == 1)
	{
		pc_color_down(gen, process->pc);
		process->pc = check_pc(process->pc + ((short)args[0] % IDX_MOD));
	}
}
