#include "vm.h"

int		validate_cod_byte(int op_num, uint32_t *args)
{
	size_t		i;

	i = 0;
	while (i < op[op_num].nbr_arg)
	{
		if (!(args[i] & op[op_num].arg[i]))
			return (0);
		i++;
	}
	if (args[i]) // to much args
		return (0);
	return (1);
}

void	get_step(int op_num, int *step, uint32_t arg)
{
	if (arg)
	{
		if (arg == REG_CODE)
			(*step) += REG_READ;
		else if (arg == DIR_CODE)
			(*step) += op[op_num].flag_direct_size;
		else
		{
			arg = T_IND; // maybe adress
			(*step) += IND_READ;
		}
	}
}

int		check_cod_byte(int op_num, unsigned char codbyte, int *step, uint32_t *args)
{
	size_t		i;
	size_t		shift;

	i = 0;
	shift = 6;
	if (!op[op_num].coding_byte)
	{
		args[i] = (uint32_t)op[op_num].arg[0];
		get_step(op_num, step, args[i]); //wtf?
		return (1);
	}
	(*step)++;
	while (i < MAX_ARGS_NUMBER)
	{
		args[i] = (uint32_t)(codbyte >> shift) & 3;
		get_step(op_num, step, args[i]); //wtf?
		shift -= 2;
		i++;
	}
	return (validate_cod_byte(op_num, args));
}

uint32_t	uncode_arg(unsigned char *field, size_t *curr, int size)
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

void	fetch_args(unsigned char *field, t_process *proc, int op_num, uint32_t *args)
{
	size_t		i;
	size_t		curr;

	curr = check_pc(proc->pc + 2);
	i = 0;
	while (i < op[op_num].nbr_arg)
	{
		if (args[i] == T_REG)
		{
			args[i] = (uint32_t)field[curr];
			curr = check_pc(curr + 1);
		}
		else if (args[i] == T_DIR)
			args[i] = uncode_arg(field, &curr, op[op_num].flag_direct_size);
		else if (args[i] == T_IND)
		{
			args[i] = uncode_arg(field, &curr, IND_READ);
			curr = proc->pc + args[i];
			args[i] = uncode_arg(field, &curr, IND_SIZE);
		}
		i++;
	}
}

size_t		check_pc(size_t pc)
{
	if (pc > MEM_SIZE)
		pc = pc % MEM_SIZE;
	return (pc);
}

void	fetch(t_general *gen, t_process *process, int op_num)
{
	int 		step;
	uint32_t	args[MAX_ARGS_NUMBER];
	size_t		curr;

	step = 0;
	curr = check_pc(process->pc + 1);
	while (step < MAX_ARGS_NUMBER)
		args[step++] = 0;
	step = 1;
	if (check_cod_byte(op_num, gen->field[curr], &step, args))
	{
		fetch_args(gen->field, process, op_num, args);
		op[op_num].f(gen, process, op_num, args);
	}
	process->pc += step;
}
