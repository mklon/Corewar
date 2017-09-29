#include "../vm.h"

void				lld_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uncode_args(gen->field, process, op_num, args);
	if (args[1] >= 1 && args[1] <= 16)
	{
		process->reg[args[1]] = args[0];
		process->carry = (char)((process->reg[args[1]] == 0) ? 1 : 0);
	}
}
