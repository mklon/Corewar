#include "../vm.h"

void	st(t_general *gen, t_process *process, int op_num, int *args)
{
	uint32_t		args_val[MAX_ARGS_NUMBER];

	args_copy(args, args_val, op[op_num].nbr_arg);
	uncode_args(gen->field, process, op_num, args_val);
	if (args[1] == T_REG)
	{
		if (args_val[0] >= 0 && args_val[0] <= 16 && args_val[1] >= 0
			&& args_val[1] <= 16)
		{
			args_val[1] = args_val[1] % IDX_MOD;
			proc->reg[args_val[0]] = args_val[1];
		}
	}
	else
	{
		
	}
}