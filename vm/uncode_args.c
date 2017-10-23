/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uncode_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:05:00 by msymkany          #+#    #+#             */
/*   Updated: 2017/10/12 13:05:04 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		args_copy(uint32_t *args, uint32_t *args_val, size_t nbr_arg)
{
	size_t		i;

	i = 0;
	while (i < nbr_arg)
	{
		args_val[i] = args[i];
		i++;
	}
}

uint32_t	convert_arg(unsigned char *field, size_t *curr, size_t size)
{
	size_t		j;
	uint32_t	res;

	j = 0;
	res = 0;
	while (j < size)
	{
		*curr = check_pc(*curr);
		res = res << 8;
		res |= field[(*curr)];
		(*curr)++;
		j++;
	}
	return (res);
}

uint32_t	get_ind(unsigned char *field, size_t curr)
{
	uint32_t		arg;

	arg = convert_arg(field, &curr, IND_SIZE);
	return (arg);
}

void		uncode_args(unsigned char *field, t_process *proc, int op_num,
					uint32_t *ar)
{
	size_t		i;
	size_t		curr;
	short		ind;

	curr = check_pc(proc->pc + 1 + (g_op[op_num].coding_byte));
	i = 0;
	while (i < g_op[op_num].nbr_arg)
	{
		if (ar[i] == T_REG)
		{
			ar[i] = (uint32_t)field[curr];
			curr = check_pc(curr + 1);
		}
		else if (ar[i] == T_DIR)
			ar[i] = convert_arg(field, &curr, g_op[op_num].flag_direct_size);
		else if (ar[i] == T_IND)
		{
			ind = (short)convert_arg(field, &curr, IND_READ);
			if (op_num != 12)
				ind = ind % IDX_MOD;
			ar[i] = ((op_num != 2) ? get_ind(field, (proc->pc + ind)) : ind);
		}
		i++;
	}
}
