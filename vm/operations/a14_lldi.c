/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a14_lldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:48:24 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/10/11 21:48:24 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	lldi_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uint32_t		val[MAX_ARGS_NUMBER];
	int				first;
	int				second;
	size_t			sum_go;

	args_copy(args, val, g_op[op_num].nbr_arg);
	uncode_args(gen->field, process, op_num, val);
	if (!(val_reg(args[2], val[2]) && val_reg(args[0], val[0])
		&& val_reg(args[1], val[1])))
		return ;
	first = ((args[0] == T_REG) ? process->reg[val[0]] : val[0]);
	if (args[0] == T_DIR)
		first = (short)val[0];
	second = ((args[1] == T_REG) ? process->reg[val[1]] : (short)val[1]);
	sum_go = check_pc(process->pc + (first + second));
	if (gen->debug)
	{
		ft_printf("P%7u | lldi %d %d r%u\n", process->num,
				first, second, val[2]);
		ft_printf("         | %d + %d = %d -> go %d (mod)\n", first,
				second, (first + second), sum_go, process->pc);
	}
	process->reg[val[2]] = convert_arg(gen->field, &sum_go, REG_SIZE);
	process->carry = (char)((process->reg[val[2]] == 0) ? 1 : 0);
}
