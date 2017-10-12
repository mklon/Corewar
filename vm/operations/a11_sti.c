/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a11_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:48:02 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/10/11 21:48:02 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	sti_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uint32_t		val[MAX_ARGS_NUMBER];
	int				first;
	int				second;
	size_t			sum_go;

	args_copy(args, val, g_op[op_num].nbr_arg);
	uncode_args(gen->field, process, op_num, val);
	if (!(val_reg(args[0], val[0]) && val_reg(args[1], val[1])
		&& val_reg(args[2], val[2])))
		return ;
	first = ((args[1] == T_REG) ? process->reg[val[1]] : val[1]);
	if (args[1] == T_DIR)
		first = (short)val[1];
	second = ((args[2] == T_REG) ? process->reg[val[2]] : (short)val[2]);
	sum_go = check_pc(process->pc + ((first + second) % IDX_MOD));
	if (gen->debug)
	{
		ft_printf("P%7u | sti r%u %d %d\n", process->num,
				val[0], first, second);
		ft_printf("         | %d + %d = %d -> go %d\n", first, second,
			(first + second), sum_go);
	}
	put_numb_on_field(gen, sum_go, process->reg[val[0]], process->color);
}
