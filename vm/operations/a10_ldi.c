/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a10_ldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:47:53 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/10/11 21:47:54 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	ldi_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uint32_t		args_val[MAX_ARGS_NUMBER];
	int				first;
	int				second;
	size_t			sum_go;

	args_copy(args, args_val, g_op[op_num].nbr_arg);
	uncode_args(gen->field, process, op_num, args_val);
	if (!(val_reg(args[2], args_val[2]) && val_reg(args[0], args_val[0])
		&& val_reg(args[1], args_val[1])))
		return ;
	first = ((args[0] == T_REG) ? process->reg[args_val[0]] : args_val[0]);
	if (args[0] == T_DIR)
		first = (short)args_val[0];
	second = ((args[1] == T_REG) ? process->reg[args_val[1]] :
			(short)args_val[1]);
	sum_go = check_pc(process->pc + ((first + second) % IDX_MOD));
	if (gen->debug)
	{
		ft_printf("P%7u | ldi %d %d r%u\n", process->num,
				first, second, args_val[2]);
		ft_printf("         | %d + %d = %d -> go %d\n", first, second,
				(first + second), sum_go);
	}
	process->reg[args_val[2]] = convert_arg(gen->field, &sum_go, REG_SIZE);
}
