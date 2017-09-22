#include "../vm.h"

void		ld_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	if (args[1] >= 0 && args[1] <= 16)
	{
		args[0] = args[0] % IDX_MOD;
		process->reg[args[1]] = args[0];
		process->carry = (process->reg[args[]] == 0) ? 1 : 0;
	}
	return ;
}
