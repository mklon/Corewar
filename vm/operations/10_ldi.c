#include "../vm.h"

void		ldi_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	int		index;

	index = 0;
	if (args[1] >= 0 && args[1] <= 16 && args[2] >= 0 && args[2] <= 16
		&& args[3] >= 0 && args[3] <= 16)
	{
		index = args[1] + args[2];
		index = index % IDX_MOD;
		args[3] = index;
		// process->carry = (proc->reg[args[3]] == 0) ? 1 : 0;//??
	}
}
