
#include "../vm.h"

void	and_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uint32_t		args_val[MAX_ARGS_NUMBER];

	args_copy(args, args_val, op[op_num].nbr_arg);
	uncode_args(gen->field, process, op_num, args_val);
	if (args[0] == T_REG && (args_val[0] >= 1 && args_val[0] <= REG_NUMBER))
	{
		if (op_num == 5)
			process->reg[args_val[2]] = process->args_val[0] & process->args_val[1];
		if (op_num == 6)
			process->reg[args_val[2]] = process->args_val[0] | process->args_val[1];
		if (op_num == 7)
			process->reg[args_val[2]] = process->args_val[0] ^ process->args_val[1];
	}

	process->carry = (process->reg[args_val[2]] == 0) ? 1 : 0;
//	if (args[1] >= 0 && args[1] <= 16 && args[2] >= 0 && args[2] <= 16)
//		//&& args[3] >= 0 && args[3] <= 16) ??
//	{
//		args[3] = args[1] + args[2];
//		process->carry = (process->reg[args[3]] == 0) ? 1 : 0;
//	}
}
