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

void		fetch(t_general *gen, t_process *process, int op_num)
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
		op[op_num].f(gen, process, op_num, args);
	}
	if (op_num != 8) // not jump
		process->pc += step;
}
