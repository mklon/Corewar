/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a3_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:46:22 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/10/11 21:46:23 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	st_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uint32_t		val[MAX_ARGS_NUMBER];
	size_t			copy_pc;

	copy_pc = 0;
	args_copy(args, val, g_op[op_num].nbr_arg);
	uncode_args(gen->field, process, op_num, val);
	if (!(val_reg(args[0], val[0])))
		return ;
	if (val_reg(args[1], val[1]) == 1)
	{
		process->reg[val[1]] = process->reg[val[0]];
		if (gen->debug)
			ft_printf("P%7u | st r%u r%u\n", process->num, val[0],
					val[1]);
	}
	else
	{
		copy_pc = check_pc(process->pc + val[1]);
		put_numb_on_field(gen, copy_pc, process->reg[val[0]], process->color);
		if (gen->debug)
			ft_printf("P%7u | st r%u %hd (mod)\n", process->num, val[0],
					(short)val[1]);
	}
}

void	put_numb_on_field(t_general *gen, size_t copy_pc, int args, int color)
{
	gen->field[copy_pc] = (unsigned char)(args >> 24);
	gen->field[check_pc(copy_pc + 1)] = (unsigned char)(args >> 16);
	gen->field[check_pc(copy_pc + 2)] = (unsigned char)(args >> 8);
	gen->field[check_pc(copy_pc + 3)] = (unsigned char)(args);
	if (gen->visual)
	{
		if (color == 1)
			color = 14;
		else if (color == 2)
			color = 15;
		else if (color == 3)
			color = 16;
		else if (color == 4)
			color = 17;
		gen->colors[copy_pc] = color;
		gen->colors[check_pc(copy_pc + 1)] = color;
		gen->colors[check_pc(copy_pc + 2)] = color;
		gen->colors[check_pc(copy_pc + 3)] = color;
		gen->holdup[copy_pc] = 50;
		gen->holdup[check_pc(copy_pc + 1)] = 50;
		gen->holdup[check_pc(copy_pc + 2)] = 50;
		gen->holdup[check_pc(copy_pc + 3)] = 50;
	}
}
