#include "../vm.h"

void	ld_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uint32_t		args_val[MAX_ARGS_NUMBER];

	args_copy(args, args_val, op[op_num].nbr_arg);
	uncode_args(gen->field, process, op_num, args_val);
	if (args_val[1] >= 1 && args_val[1] <= 16)
	{
		if (args[0] == T_IND)
		{
			process->reg[args_val[1]] = args_val[0];
		}
		else
		{
			process->reg[args_val[1]] = args_val[0];
		}
		process->carry = (process->reg[args_val[1]] == 0) ? 1 : 0;
	}
	return ;
}
