#include "../vm.h"

void	sti_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uint32_t		args_val[MAX_ARGS_NUMBER];
	uint32_t		first;
	uint32_t		second;
	size_t			sum_go;

	args_copy(args, args_val, op[op_num].nbr_arg);
	uncode_args(gen->field, process, op_num, args_val);
	if (!(args_val[0] >= 1 && args_val[0] <= 16)
		|| (args[1] == T_REG && !(args_val[1] >= 1 && args_val[1] <= 16))
		|| (args[2] == T_REG && !(args_val[2] >= 1 && args_val[2] <= 16)))
			return ;
	first = ((args[1] == T_REG) ? process->reg[args_val[1]] : args_val[1]);
	second = ((args[2] == T_REG) ? process->reg[args_val[2]] : args_val[2]);
	sum_go = (first + second) % IDX_MOD;
	sum_go = check_pc(process->pc + sum_go);
	put_numb_on_field(gen, sum_go, args_val[0]);
}
