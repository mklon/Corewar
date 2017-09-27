#include "../vm.h"

void	st(t_general *gen, t_process *process, int op_num, int *args)
{
	uint32_t		args_val[MAX_ARGS_NUMBER];
	size_t		copy_pc;

	copy_pc = 0;
	args_copy(args, args_val, op[op_num].nbr_arg);
	uncode_args(gen->field, process, op_num, args_val);
	if (!(args_val[0] >= 1 && args_val[0] <= REG_NUMBER))
		return ;
	if (args[1] == T_REG && (args_val[1] >= 1 && args_val[1] <= REG_NUMBER))
		process->reg[args_val[1]] = process-reg[args_val[0]];
	else
	{
		copy_pc = check_pc(process->pc + args_val[1]);
		gen->field[copy_pc];
		put_numb_on_field(gen, copy_pc, args[]);
	}
}
