#include "vm.h"

void		args_copy(uint32_t *args, uint32_t *args_val, int nbr_arg)
{
	int 	i;

	i = 0;
	while (i < nbr_arg)
	{
		args_val[i] = args[i];
		i++;
	}
}

uint32_t	convert_arg(unsigned char *field, size_t *curr, int size)
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

uint32_t		get_ind(unsigned char *field, size_t curr)
{
	uint32_t		arg;

	arg = convert_arg(field, &curr, IND_SIZE);
	return (arg);
}

void	uncode_args(unsigned char *field, t_process *proc, int op_num, uint32_t *args)
{
	size_t		i;
	size_t		curr;
	int 		ind;

	curr = check_pc(proc->pc + 1 + (op[op_num].coding_byte));
	i = 0;
	while (i < op[op_num].nbr_arg)
	{
		if (args[i] == T_REG)
		{
			args[i] = (uint32_t)field[curr];
			curr = check_pc(curr + 1);
		}
		else if (args[i] == T_DIR)
			args[i] = convert_arg(field, &curr, op[op_num].flag_direct_size);
		else if (args[i] == T_IND)
		{
			ind = convert_arg(field, &curr, IND_READ);
			if (ind >= MEM_SIZE)
				ind = ind % MEM_SIZE - MEM_SIZE;
			if (op_num != 12 && op_num != 13)// && op_num != 9) // not lld, lldi, not!! ldi
				ind = ind % IDX_MOD;
			if (op_num != 2) // not st
				ind = get_ind(field, (proc->pc + ind));
			args[i] = (uint32_t)ind;
//			args[i] = check_pc(convert_arg(field, &curr, IND_READ));
//			if (op_num != 12 && op_num != 13)// && op_num != 9) // not lld, lldi, not!! ldi
//				args[i] = args[i] % IDX_MOD;
//			if (op_num != 2) // not st
//				args[i] = get_ind(field, (proc->pc + args[i]));
		}
		i++;
	}
}
