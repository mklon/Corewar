
#include "../vm.h"

void		add_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	fetch_args(gen->field, process, op_num, args);
	if (args[0] >= 1 && args[0] <= REG_NUMBER &&
		args[1] >= 1 && args[1] <= REG_NUMBER &&
		args[2] >= 1 && args[2] <= REG_NUMBER)
	{
		process->reg[args[2]] = args[0] + args[1];
		process->carry = (char)((process->reg[args[3]] == 0) ? 1 : 0); //?
	}
}
