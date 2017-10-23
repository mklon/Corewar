/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:07:39 by msymkany          #+#    #+#             */
/*   Updated: 2017/10/12 13:07:41 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		validate_cod_byte(int op_num, uint32_t *args)
{
	size_t		i;

	i = 0;
	while (i < g_op[op_num].nbr_arg)
	{
		if (!(args[i] & g_op[op_num].arg[i]))
			return (0);
		i++;
	}
	if (args[i])
		return (0);
	return (1);
}

void	get_step(int op_num, size_t *step, uint32_t arg)
{
	if (arg)
	{
		if (arg == REG_CODE)
			(*step) += REG_READ;
		else if (arg == DIR_CODE)
			(*step) += g_op[op_num].flag_direct_size;
		else
			(*step) += IND_READ;
	}
}

int		check_cod_byte(int op_num, unsigned char codbyte, size_t *step,
	uint32_t *args)
{
	size_t		i;
	size_t		shift;

	i = 0;
	shift = 6;
	if (!g_op[op_num].coding_byte)
	{
		args[i] = (uint32_t)g_op[op_num].arg[0];
		get_step(op_num, step, args[i]);
		return (1);
	}
	(*step)++;
	while (i < g_op[op_num].nbr_arg)
	{
		args[i] = (uint32_t)(codbyte >> shift) & 3;
		if (args[i] == IND_CODE)
			args[i] = T_IND;
		get_step(op_num, step, args[i]);
		shift -= 2;
		i++;
	}
	return (validate_cod_byte(op_num, args));
}

void	fetch(t_general *gen, t_process *process, int op_num)
{
	size_t		step;
	uint32_t	args[MAX_ARGS_NUMBER];
	size_t		curr;

	step = 0;
	curr = check_pc(process->pc + 1);
	while (step < MAX_ARGS_NUMBER)
		args[step++] = 0;
	step = 1;
	if (check_cod_byte(op_num, gen->field[curr], &step, args))
	{
		if (op_num == 8 && process->carry == 1)
			step = 0;
		g_op[op_num].f(gen, process, op_num, args);
	}
	pc_color_down(gen, process->pc);
	process->pc += step;
}
