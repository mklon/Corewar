#include "vm.h"

int		validate_cod_byte(int op_num, int *args)
{
	size_t		i;

	i = 0;
	while (i < op[op_num].nbr_arg)
	{
		if (!(args[i] && op[op_num].arg[i]))
			return (0);
		i++;
	}
	if (args[i]) // to much args
		return (0);
	return (1);
}

void	get_step(int op_num, int *step, int arg)
{
	if (arg)
	{
		if (arg == REG_CODE)
			(*step) += REG_READ;
		else if (arg == DIR_CODE)
			(*step) += op[op_num].flag_direct_size;
		else
		{
			arg = T_IND;
			(*step) += IND_READ;
		}
	}
}

int		check_cod_byte(int op_num, unsigned char codbyte, int *step, int *args)
{
	size_t		i;
	size_t		shift;

	i = 0;
	shift = 6;
	if (!op[op_num].coding_byte)
	{
		args[i] = op[op_num].arg[0];
		get_step(op_num, step, args[i]); //wtf?
		return (1);
	}
	while (i < MAX_ARGS_NUMBER)
	{
		args[i] = codbyte && (192 >> shift);
		get_step(op_num, step, args[i]); //wtf?
		shift -= 2;
		i++;
	}
	return (validate_cod_byte(op_num, args));
}

//void	fetch_args(unsigned char *field, t_process *proc, int op_num, int **args)
//{
//	size_t		i;
//	size_t		curr;
//
//	curr = proc->pc + 2;
//	i = 0;
//	while (i < op[op_num].nbr_arg)
//	{
//		if ((*arg) == REG_CODE)
//			(*step) += REG_READ;
//		else if (*arg == DIR_CODE)
//			(*step) += op[op_num].flag_direct_size;
//		else
//		{
//			*arg = T_IND;
//			(*step) += IND_READ;
//		}
//	}
//
//}

void	fetch(t_general *gen, t_process *process, int op_num)
{
	int 		step;
	int 		args[MAX_ARGS_NUMBER];

	step = 1;
	ft_memset(args, 0, MAX_ARGS_NUMBER);
	if (check_cod_byte(op_num, gen->field[process->pc + 1], &step, args))
	{
//		fetch_args(gen->field, process, op_num, &args);
		op[op_num].f(gen, process, op_num, args);
	}
	process->pc += step;
}
